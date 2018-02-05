#include <iostream>
#include <chrono>
#include <random>

int* gen_rand_list(int size) {

    std::mt19937_64 generator;
    std::uniform_int_distribution<int> distribution(-size/2,size);
    int* nlist = new int[size];
    for (int i = 1; i < size; i++) {
        nlist[i] = distribution(generator);
    }
    return nlist;
}

void delete_array(int* arr) {
    delete[] arr;
}

int mss1(int* arr, int len) {

    for (int i = 0; i < len; i++) {
        int max = 0;
        for (int j = i; j < len; j++) {
            int sum = 0;
            for (int k = i; k < j; k++) {
                sum += arr[k];
            }
            if (sum > max) max = sum;
        }
    }
    return max;
}

int mss2(int* arr, int len) {

    int* pre_sum = new int[len];
    pre_sum[0] = 0;
    for (int i = 1; i < len; i++) {
        pre_sum[i] = pre_sum[i-1] + arr[i];
    }
    for (int i = 0; i < len; i++) {
        max = 0;
        for (int j = i; j < len; j++) {
            if (pre_sum[j] - pre_sum[i] > max) {
                max = pre_sum[j] - pre_sum[i];
            }
        }
    }
    delete pre_sum;
    return max;
}

int mss3(int* arr, int len) {

    return 0;
}

int main() {
    return 0;
}
