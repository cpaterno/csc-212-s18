//
// Created by tom on 4/1/18.
//

#include "quick_sort.h"

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quicksort(int *arr, int n) {
    if (n > 1) {
        int pivot = partition(arr, n);
        quicksort(arr, pivot);
        quicksort(arr+pivot+1, n-pivot-1);
    }
}

int partition(int *arr, int n) {
    int pivot = arr[0];
    int i=1, j=n-1;
    while (i <= j) {
        while (i < n && arr[i] < pivot) ++i;
        while (j > 0 && arr[j] > pivot) --j;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            ++i;
            --j;
        }
    }
    swap(&arr[0], &arr[j]);
    return j;
}
