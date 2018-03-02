# Lab 7: MergeSort -> Merge Sort -> eegMr orSt -> eegMorrSt

Mergesort is a divide and conquer algorithm that was invented by John von Neumann in 1945 [[*ref*](https://en.wikipedia.org/wiki/Merge_sort)]. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves [[*ref*](http://www.geeksforgeeks.org/merge-sort/)]. You may want to see a [visualization of MergeSort](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html) to help understand the algorithm.

Here is the visualization from wikipedia which does a good job of showing the basic Merge Sort process:
![image](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)

To begin, download the starter code, which includes the test cases, and the main.cpp file.

The google form for submitting can be found at [here.](https://goo.gl/forms/698FDcXRPttM5q6b2) The instructors will inform you when the link is active.

## 1. Implementing Merge

Merge algorithms are a family of algorithms that take multiple sorted lists as input and produce a single list as output, containing all the elements of the inputs lists in sorted order. [[*ref*](https://en.wikipedia.org/wiki/Merge_algorithm)]. Today you will be merging two lists together in linear time, and in linear space or less. Your goal will be to transform the whole array `A` to be sorted in non-decreasing order.

The function header you will be using is:

```c++
void merge(int* A, int n, int mid);
```

Where:

* `A` is an array of integers, of length `n`, where `A` from `0` to `mid-1` is sorted in non-decreasing order, and `A` from `mid` to `n-1` is also sorted in non-decreasing order. The whole array is not necessarily sorted in non-decreasing order.
* `n` is the length of array `A`
* `mid`, while not necessarily the midpoint, it is the point in `A` where the two sorted sections meet

Here is an example of an array `A`:

![Example Pic](/lab-07/array.png?raw=true "Example Array") 

Loose pseudocode for the algorithm is as follows:

1. Allocate Memory Dynamically to array B, size of n
2. Copy A to B
3. Merge Back into A
4. Deallocate Memory (B)


## 2. Testing out Merge

Once you feel that you're ready to test your `merge` function, recompile your code using the statement below.

```bash
$ g++ -std=c++11 -g lab7.cc -o lab7
```

You may then use the `lab7` file to test your `merge` function by running the line below, with `INPUT_SIZE` replaced with a positive integer. If your function works correctly, the program will print out a success message for each of three trials, along with an overall success message. Otherwise, it will print at least one trial failure message, along with an overall failure message.

```bash
$ ./lab7 merge INPUT_SIZE
```


## 3. Implementing Mergesort

Now that you have merge implemented, it should be fairly easy to implement the full MergeSort. **You must have a correct implementation of `merge()` in order to complete Mergesort**

The function header is as follows:

```c++
void MergeSort(int* A, int n);
```

Where:

* `A` is an array of potentially unsorted integers
* `n` is the length of array `A`

The goal is to sort A in non-decreasing order. For more information on merge sort, refer to the [lecture slides](http://homepage.cs.uri.edu/~malvarez/teaching/212-f17/files/lecture-10-mergesort.key.pdf). This algorithm is recursive, so your function should be recursive.

## 4. Testing Mergesort

Once you feel that you're ready to test your `mergesort` function, recompile your code again using the statement below.

```bash
$ g++ -std=c++11 -g lab7.cc -o lab7
```

Just as with the `merge` function, you may use the `lab7` file to test your `mergesort` function by running the line below, with `INPUT_SIZE` replaced with a positive integer. Again, if your function works correctly, the program will print out a success message for each of three trials, along with an overall success message. Otherwise, it will print at least one trial failure message, along with an overall failure message.

```bash
$ ./lab7 mergesort INPUT_SIZE
```


## 5. Improving Mergesort

We can cut the running time of mergesort substantially with some carefully considered modifications to the implementation. Make a copy of your `MergeSort` function and name it `MergeSortPlus`, then implement the improvements below in your `MergeSortPlus` function.

* Use insertion sort for small subarrays. We can improve most recursive algorithms by handling small cases differently. Switching to insertion sort for small subarrays will improve the running time of a typical mergesort implementation by 10 to 15 percent. Input sizes between 7 and 10 (inclusive) are good choices for switching over to insertion sort.

Once you implement the first improvement, try compiling and running the function with test cases of various sizes, small and large, to verify that the algorithm still runs successfully. Also make sure you answer the following question on the google form.

> **Question 1:** Why is insertion sort better than mergesort for small subarrays?

* Test whether array is already in order. We can reduce the running time to be linear for arrays that are already in order by adding a test to skip a call to `merge()` if `a[mid]` is less than or equal to `a[mid+1]`. With this change, we still do all the recursive calls, but the running time for any sorted subarray is linear.

Once you have implemented and tested the 2nd improvement, answer the following question in the google form.

> **Question 2:** How does the change affect the running time and in what case does the change make the biggest improvement?

You may test your `mergesort_plus` function just as you tested your other two implementations, except with the argument `ms_plus` instead of `merge` or `mergesort`. It will run the same way as before, providing success and/or failure messages.


## 6. Standard vs Improved Mergesort

Now that you have implemented mergesort with and without the improvements, it is time to test their performance against one another. Without needing to recompile, you may run the line below to benchmark `mergesort` and `mergesort_plus`:

```bash
$ ./lab7 ms_vs_msp INPUT_SIZE
```

The program will output the average amount of time each of the two algorithms took to run on three different random arrays of size INPUT_SIZE. If either `merge`, `mergesort` or `mergesort_plus` did not pass its tests for various input sizes, the result of running this line will not be an accurate run time representation.

> **Question 3:** Run your program with `ms_vs_msp` on input sizes of 10, 100, 1000, 10000, 1000000 and 10000000. Which algorithm performed better, and how much would you say the difference in performance was (in words, not numbers)?

## 7. What to Submit

The google form for submitting can be found at [here.](https://goo.gl/forms/698FDcXRPttM5q6b2) The instructors will inform you when the link is active.

You will need to sumbit the source code for your Merge function. After that, there is two questions to answer:

> **Question 4:** What is the running time for MergeSort? Can you verify the slides' answer with real running times from the lab?

> **Question 5:** What class of algorithm is MergeSort (look at the slides)? Why is it that type of algorithm?
