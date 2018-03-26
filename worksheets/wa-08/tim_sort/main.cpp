/** Tim Sort courtesy of
 * https://www.geeksforgeeks.org/timsort/
 */

#include <iostream>
#include <random>

static const int RUN = 32;

void insertion_sort(int*, int, int);

void merge(int*, int, int, int);

void tim_sort(int*, int);

int* gen_arr(int n) {
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_int_distribution<int> dist(0, 1000);

    auto arr = new int[n];
    for (int i=0; i<n; ++i)
        arr[i] = dist(mt) % 1000;
    return arr;
}

bool is_sorted(const int* arr, int n) {
    if (!n) return true;
    for (int i=1; i<n; ++i)
        if (arr[i-1] > arr[i]) return false;
    return true;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int* arr;
    for (int i=32; i<50; ++i) {
        arr = gen_arr(i);
        std::cout << i << " " << "Before: " << is_sorted(arr, i) << std::endl;
        tim_sort(arr, i);
        std::cout << i << " " << "After: " << is_sorted(arr, i) << std::endl;
        delete[] arr;
    }
    return 0;
}

void insertion_sort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// merge function merges the sorted runs
void merge(int arr[], int l, int m, int r)
{
    int n = r-1;
    int temp[n];
    int j=l, k=m;
    for (int i=0; i<n; ++i) {
        if (j == m || (arr[k] < arr[j]))
            temp[i] = arr[k++];
        else
            temp[i] = arr[j++];
    }
    for (int i=0; i<n; ++i) arr[i] = temp[i];
}

// iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void tim_sort(int arr[], int n)
{
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        insertion_sort(arr, i, min((i+31), (n-1)));

    // start merging from size RUN (or 32). It will merge
    // to form size 64, then 128, 256 and so on ....
    for (int size = RUN; size < n; size = 2*size)
    {
        // pick starting point of left sub array. We
        // are going to merge arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we increase left by 2*size
        for (int left = 0; left < n; left += 2*size)
        {
            // find ending point of left sub array
            // mid+1 is starting point of right sub array
            int mid = left + size - 1;
            int right = min((left + 2*size - 1), (n-1));

            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            merge(arr, left, mid, right);
        }
    }
}
