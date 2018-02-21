#include <iostream>
#include <chrono>
#include <random>
#include <cmath>

#define t_p std::chrono::time_point<std::chrono::steady_clock>

int check_time(t_p start_time);

int* gen_rand_list(int size) {

    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    int* nlist = new int[size];
    for (int i = 0; i < size; i++) {
        nlist[i] = distribution(generator);
    }
    return nlist;
}

void delete_list(int* arr) {
    delete [] arr;
}

int max_sub_slow(const int* arr, int len) {
    int sum;
    int max = 0;

    // Used to make sure the algorithm hasn't run for too long
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (sum > max) max = sum;

            // If the algorithm has run for over a minute, abort and return -1
            if (check_time(start)) return -1;
        }
    }

    return max;
}

// The faster maximum subarray sum algorithm. Runs in O(n^2) time.
int max_sub_faster(const int* arr, int len) {
    int sum;
    int max;
    int* pre_sum = new int[len+1];

    // Used to make sure the algorithm hasn't run for too long
    auto start = std::chrono::steady_clock::now();

    pre_sum[0] = 0;
    for (int i = 1; i <= len; i++) {
        pre_sum[i] = pre_sum[i-1] + arr[i-1];
    }

    max = 0;
    for (int j = 1; j <= len; j++) {
        for (int k = j; k <= len; k++) {
            sum = pre_sum[k] - pre_sum[j-1];
            if (sum > max) {
                max = sum;
            }

            // If the algorithm has run for over a minute, abort and return -1
            if (check_time(start)) {
                delete [] pre_sum;
                return -1;
            }
        }
    }
    delete [] pre_sum;
    return max;
}

// The fastest maximum subarray sum algorithm. Runs in O(n) time.
int max_sub_fastest(const int* arr, int len) {
    int* pre_max = new int[len+1];
    int max;

    pre_max[0] = 0;
    for (int i = 1; i <= len; i++) {
        pre_max[i] = fmax(0, pre_max[i-1] + arr[i-1]);
    }

    max = 0;
    for (int i = 1; i <= len; i++) {
        max = fmax(max, pre_max[i]);
    }

    delete [] pre_max;
    return max;
}

// Auxiliary function to keep the program from running too long
int check_time(t_p start_time) {
    auto curr_time = std::chrono::steady_clock::now();
    double t = std::chrono::duration<double> (curr_time - start_time).count();
    return (t > 60) ? 1 : 0;
}

int main() {

    int* lists[4]; // Will store a randomly generated list for each input size.
    double times[3][4]; // Will store the resulting times after benchmarking.

    int input_sizes[4] = {10, 100, 1000, 10000};
    char input_size_s[4][8] = {"10", "100", "1000", "10000"}; // For printing. Could use itoa instead.

    // Generate the random lists
    for (int i = 0; i < 4; i++) {
        int size = input_sizes[i];
        lists[i] = gen_rand_list(size);
    }

    // Array of function pointers to allow iteration through the algorithms
    typedef int (*max_sub)(const int*, int);
    max_sub fns[] = {max_sub_slow, max_sub_faster, max_sub_fastest};

    // Benchmark the algorithms for each input size and store the results in times.
    for (int i = 0; i < 4; i++) {
        int size = input_sizes[i];
        for (int j = 0; j < 3; j++) {
            auto start = std::chrono::steady_clock::now();
            int r = fns[j](lists[i], input_sizes[i]);
            auto end = std::chrono::steady_clock::now();
            double t = std::chrono::duration<double> (end-start).count();
            times[j][i] = t;
        }
    }

    // Printing the input sizes with formatting.
    std::cout << "    ";
    int total_width = 3; // This counter keeps track of the total width of the table
    for (int i = 0; i < 4; i++) {
        int width = 0;
        // These two loops ensure the length of each column is 10 characters,
        // first printing the input size, then whitespace.
        while (input_size_s[i][width] != '\0') {
            std::cout << input_size_s[i][width];
            width++;
            total_width++;
        }
        while (width < 10) {
            std::cout << ' ';
            width++;
            total_width++;
        }
        std::cout << ' ';
        total_width++;
    }
    std::cout << std::endl;

    // Printing the rest with formatting.
    for (int i = 0; i < 7; i++) {
        if (i % 2 == 0) {
            // Prints bars and underscores on every other line as separators.
            // This level of detail is not necessary in the solutions.
            std::cout << "   ";
            for (int j = 3; j < total_width; j++) {
                if (j % 11 == 3) {
                    std::cout << '|';
                } else {
                    std::cout << '_';
                }
            }
            std::cout << '|' << std::endl;
        } else {
            // Prints the rows with actual table content otherwise
            std::cout << 'A' << (i+1)/2 << ' ';
            for (int j = 3; j < total_width; j++) {
                // Print a separator between each column
                if (j % 11 == 3) {
                    std::cout << '|';
                } else {
                    double t = times[(i-1)/2][(j-4)/11];
                    // One way to handle algorithms that run too long
                    if (t >= 60) {
                        std::cout << "N/A       ";
                    } else {
                        // floor(log10(t)) is number of digits of t, which is used to calculate the precision
                        (log10(t) >= 1) ? std::cout.precision(7 - floor(log10(t))) : std::cout.precision(7);
                        std::cout << std::fixed << times[(i-1)/2][(j-4)/11] << ' ';
                    }
                    j += 9;
                }
            }
            std::cout << '|' << std::endl;
        }
    }

    // Deallocate memory from gen_rand_list
    for (int i = 0; i < 4; i++) {
        delete_list(lists[i]);
    }

    return 0;
}
