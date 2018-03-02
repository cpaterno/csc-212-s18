#include <iostream>
#include <cstring>
#include <random>
#include <chrono>
#include <algorithm>

int* gen_list_unsorted(int n);

void merge(int* A, int n, int mid) {

}

void MergeSort(int* A, int n) {

}

/* Compares int arrays of similar length n for equality */
bool compareArrays(int* A, int* B, int n) {
    bool success = true;
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            success = false;
            break;
        }
    }
    return success;
}

void customTest(int n) {

    /* You can write your own additional tests here if you would like */

}

bool testMerge(int n, int t) {

    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(n/20, n - (n/20));

    int mid = distribution(generator);

    int* A = gen_list_unsorted(n);
    std::sort(A, A + mid);
    std::sort(A + mid, A + n);

    int* B = new int[n];
    std::memcpy(B, A, sizeof(int)*n);
    std::sort(B, B + n);

    merge(A, n, mid);

    bool success = compareArrays(A, B, n);

    if (success) {
        std::cout << "Merge successful on trial " << t << std::endl;
        return true;
    } else {
        std::cout << "Merge failed on trial " << t << std::endl;
        return false;
    }

}

bool testMergeSort(int n, int t) {

    int* A = gen_list_unsorted(n);
    int* B = new int[n];
    std::memcpy(B, A, sizeof(int)*n);
    std::sort(B, B + n);

    MergeSort(A, n);

    bool success = compareArrays(A, B, n);

    if (success) {
        std::cout << "MergeSort successful on trial " << t << std::endl;
        return true;
    } else {
        std::cout << "MergeSort failed on trial " << t << std::endl;
        return false;
    }

}

void raceMergeSorts(int n) {

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

int main(int argc, char** argv) {

    /* Input validation */
    if (argc != 3) {
        std::cerr << "Invalid Arguments. Usage: test_type(str) input_size(int)" << std::endl;
        return 1;
    }
    int num_ttypes = 4;
    char test_types[num_ttypes][11] = {"merge", "merge_sort", "ms_vs_msp", "custom"};
    bool valid = false;
    for (int i = 0; i < 4; i++) {
        if (strcmp(argv[1], test_types[i])) {
            valid = true;
            break;
        }
    }
    if (!valid) {
        std::cerr << "Invalid Arguments. Possibilities for test_type are:" << std::endl;
        for (int i = 0; i < num_ttypes; i++) {
            std::cout << test_types[i] << std::endl;
        }
        return 2;
    }
    if (atoi(argv[2]) <= 0) {
        std::cerr << "Invalid Arguments. Please enter a valid number n > 0.";
        return 3;
    }


    int input_size = atoi(argv[2]);
    if (!strcmp(argv[1], test_types[0])) {

        bool success = true;
        for (int i = 0; i < 3; i++) {
            success = success && testMerge(input_size, i+1);
        }
        if (success) {
            std::cout << "Merge successful for input size " << input_size << std::endl;
        } else {
            std::cout << "Merge failed for input size " << input_size << std::endl;
        }

    } else if (!strcmp(argv[1], test_types[1])) {

        bool success = true;
        for (int i = 0; i < 3; i++) {
            success = success && testMergeSort(input_size, i+1);
        }
        if (success) {
            std::cout << "MergeSort successful for input size " << input_size << std::endl;
        } else {
            std::cout << "MergeSort failed for input size " << input_size << std::endl;
        }

    } else if (!strcmp(argv[1], test_types[2])) {

        raceMergeSorts(input_size);

    } else if (!strcmp(argv[1], test_types[3])) {

        customTest(input_size);

    }
    return 0;
}
