#include <iostream>
#include <chrono>
#include <random>
#include <cmath>

#define t_p std::chrono::time_point<std::chrono::steady_clock>

int check_time(t_p start_time);

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

// Generate an array of random integers. The range is +/- the size of the array
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

// Deallocate an array on the heap. A function alias for the delete keyword
void delete_list(int* arr) {
    delete [] arr;
}

// Auxiliary function to keep the program from running too long
int check_time(t_p start_time) {
    auto curr_time = std::chrono::steady_clock::now();
    double t = std::chrono::duration<double> (curr_time - start_time).count();
    return (t > 60) ? 1 : 0;
}

int main() {

    /* Creates an array containing the Maximum Subarray Sum functions
     *
     * To call a function from this array, use the following line:
     *
     *      fns[i](a, b, c);
     *
     * Where i is the index of the function to be used, and a, b, and c are the parameters
     *    i = 0 : max_sub_slow
     *    i = 1 : max_sub_faster
     *    i = 2 : max_sub_fastest
     *
     * This can be used to benchmark the different implementations without having to
     * repeat code.
     */
    typedef int (*max_sub)(const int*, int);
    max_sub fns[] = {max_sub_slow, max_sub_faster, max_sub_fastest};

    /* Student code starts here */

    return 0;
}
