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

    /* Paste your code from lab 4 here */

    return 0;
}
