#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Implement your sorting algorithms here */

// C++ Library Sorting Algorithm
void cpp_sort(int* arr, int len) {
    std::sort(arr, arr+len);
}

// Generate a random, unsorted list
int* gen_list_unsorted(int size) {

    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    int* nlist = new int[size];
    for (int i = 0; i < size; i++) {
        nlist[i] = distribution(generator);
    }
    return nlist;
}

// Generate a sorted list
int* gen_list_sorted(int size) {

    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    int* nlist = new int[size];
    for (int i = 0; i < size; i++) {
        nlist[i] = distribution(generator);
    }
    std::sort(nlist, nlist+size);

    return nlist;
}

// Generate a list that is sorted in reverse
int* gen_list_reversed(int size) {

    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    int* nlist = new int[size];
    for (int i = 0; i < size; i++) {
        nlist[i] = distribution(generator);
    }
    std::sort(nlist, nlist+size);

    for (int i = 0; i < size/2; i++) {
        swap(nlist+i, nlist+(size-i-1));
    }

    return nlist;
}

// Generate a list that is almost sorted
int* gen_list_partial_sorted(int size) {

    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    std::uniform_int_distribution<int> index_distribution(0,size-1);
    int* nlist = new int[size];
    for (int i = 0; i < size; i++) {
        nlist[i] = distribution(generator);
    }
    std::sort(nlist, nlist+size);

    for (int i = 0; i < size / 4; i++) {
        int idx1 = index_distribution(generator);
        int idx2 = index_distribution(generator);
        swap(nlist+idx1, nlist+idx2);
    }

    return nlist;
}

// Generate a list with only a small amount of unique elements
int* gen_list_few_unique(int size) {

    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-5,5);
    int* nlist = new int[size];
    for (int i = 0; i < size; i++) {
        nlist[i] = distribution(generator);
    }

    return nlist;
}

/* Auxiliary Functions */
int* copy_array(int* arr, int len) {
    int* copy = new int[len];
    for (int i = 0; i < len; i++) {
        copy[i] = arr[i];
    }
    return copy;
}


int main() {
    
    int* lists[4]; // Will store a randomly generated list for each input size.
    double times[3][4]; // Will store the resulting times after benchmarking.

    int input_sizes[4] = {50, 50, 50, 50};
    char input_size_s[4][8] = {"Random Unsorted", "Already Sorted", "Reverse Sorted", "Partially Sorted"}; // For printing. Could use itoa instead.

    //Insertion
    for (int j = 0; j < 4; j++) {
        auto start = std::chrono::steady_clock::now();
        int r = fns[j](lists[i], input_sizes[i]);
        auto end = std::chrono::steady_clock::now();
        double t = std::chrono::duration<double> (end-start).count();
        times[j][i] = t;
    }
    //Selection
    for (int j = 0; j < 4; j++) {
        auto start = std::chrono::steady_clock::now();
        int r = fns[j](lists[i], input_sizes[i]);
        auto end = std::chrono::steady_clock::now();
        double t = std::chrono::duration<double> (end-start).count();
        times[j][i] = t;
    }
    //cpp_sort
    for (int j = 0; j < 4; j++) {
        auto start = std::chrono::steady_clock::now();
        int r = fns[j](lists[i], input_sizes[i]);
        auto end = std::chrono::steady_clock::now();
        double t = std::chrono::duration<double> (end-start).count();
        times[j][i] = t;
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
