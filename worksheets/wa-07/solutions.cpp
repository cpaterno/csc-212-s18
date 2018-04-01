/** Solutions to problem set 7
 *
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

int bin_search_exact(const int target, const int* arr, int n);
int bin_search_closest(const int target, const int* arr, int n);
void merge_sort(int* arr, int n);

/** Optional Question
 *
 */
int interpolation_search(const int target, const int* arr, int n);

/** Helpers
 *
 */

void print_arr(const int* arr, const int n) {
    for (int i=0; i<n; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

bool is_sorted(const int* arr, const int n) {
    for (int i = 1; i<n; ++i) if (arr[i-1] > arr[i]) return false;
    return true;
}

int* gen_sorted_list(const int n) {
    int* list = new int[n];
    for (int i=0; i<n; ++i) list[i] = i;
    return list;
}

int* gen_rand_list(const int n) {
    int* list = new int[n];
    for (int i=0; i<n; i++) list[i] = rand() % 1000;
    return list;
}

int main() {
    // Seed random for test case generation.
    srand(time(NULL));
    std::cout << "Question 2: " << std::endl;
    int a_arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int r = bin_search_exact(2, a_arr, sizeof(a_arr)/sizeof(a_arr[0]));
    std::cout << r << std::endl;


    std::cout << "\nQuestion 3:" << std::endl;
    int b_arr[] = {5, 7, 8, 9};
    r = bin_search_exact(10, b_arr, sizeof(b_arr)/sizeof(b_arr[0]));
    std::cout << r << std::endl;


    std::cout << "\nBoth Questions with closest search:" << std::endl;
    r = bin_search_closest(2, a_arr, sizeof(a_arr)/sizeof(a_arr[0]));
    std::cout << r << std::endl;

    r = bin_search_closest(10, b_arr, sizeof(b_arr)/sizeof(b_arr[0]));
    std::cout << r << std::endl;
    
    std::cout << "\nMerge Sort" << std::endl;
    for (int i=3; i<15; ++i) {
        int* list = gen_rand_list(i);
        // std::cout << "\nArray in: ";
        // print_arr(list, i);
        
        merge_sort(list, i);
        
        // std::cout << "Array out: ";
        // print_arr(list, i);
        std::cout << "Is sorted? " << is_sorted(list, i) << std::endl;
        delete[] list;
    }


    std::cout << "\nBoth Questions with interpolation search:" << std::endl;
    r = interpolation_search(2, a_arr, sizeof(a_arr)/sizeof(a_arr[0]));
    std::cout << r << std::endl;

    r = interpolation_search(10, b_arr, sizeof(b_arr)/sizeof(b_arr[0]));
    std::cout << r << std::endl;

    return 0;
}

int bin_search_exact(const int target, const int* arr, int n) {
    std::cout << "n: " << n << " mid: " << n/2 << " arr[mid]: " << arr[n/2] << ": arr: ";
    print_arr(arr, n);

    // Base Case
    if (!n) return -1;

    int mid = (n)/2;

    if (arr[mid] == target) return arr[mid];

    else if (arr[mid] < target) return bin_search_exact(target, arr+(mid)+1, n-mid-1);
    else return bin_search_exact(target, arr, mid);
}

int bin_search_closest(const int target, const int* arr, int n) {
    std::cout << "n: " << n << " mid: " << n/2 << " arr[mid]: " << arr[n/2] << ": arr: ";
    print_arr(arr, n);

    // Base Case
    if (n == 1) return arr[0];

    int mid = (n)/2;

    if (arr[mid] == target) return arr[mid];

    else if (arr[mid] < target) return bin_search_closest(target, arr+(mid)+1, n-mid-1);
    else return bin_search_closest(target, arr, mid);
}

void merge(int arr[], int m, int n) {
    // Temp array.
    int B[n];
    
    // Merge the two halves into the temp array.
    int j=0, k=m;
    for (int i=0; i < n; ++i) {
        if (j == m || (k < n && arr[k] < arr[j]))
            B[i] = arr[k++];
        else
            B[i] = arr[j++];
    }

    for (int i=0; i<n; ++i) arr[i] = B[i];
}

void merge_sort(int arr[], int n) {
    if (n <= 1) return;

    int mid = n/2;
    
    merge_sort(arr, mid);
    merge_sort(arr+mid, n-mid);

    merge(arr, mid, n);
}

/** Remaining Questions:
 *
 * 6. Merge Sort is preferrable because it operates in O(n log n) time on large datasets, whereas
 * Insertion Sort can operates in O(n^2).
 *
 * 7. Sometimes insertion sort can outperform merge sort because of the large overhead to merge
 * small arrays.
 *
 * Most consider the turning point to be around 7-10 integers, where the overhead of merge sort allows
 * insertion sort to be faster. Thus, most advanced algorithms will perform a hybrid-search,
 * combining the best of both worlds by switching to insertion sort once the number of elements
 * falls below some threshold.
 *
 * 8. The stability of merge sort depends on the implementation, however most basic implementations
 * are stable.
 *
 */

int interpolation_search(const int target, const int* arr, int n) {
    std::cout << "n: " << n << " est: " << target / arr[n-1] << " arr[est]: " << arr[target / arr[n-1]] << ": arr: ";
    print_arr(arr, n);

    // Base Case
    if (n <= 0) return -1;

    // The only difference to regular bin search, estimating where the value is:
    int est = ((target-arr[0]) * arr[n-1]) / (arr[n-1] - arr[0]);

    if (arr[est] == target) return arr[est];

    else if (arr[est] < target) return interpolation_search(target, arr+(est)+1, n-est-1);
    else return interpolation_search(target, arr, est);
}
