# Lab 05: Basic Sorting Algorithms with Different Input Types
```
What does a sorting algorithm say when it's broken?

Out of order!
```
## Introduction

This lab will be a continuation of the previous lab, but without teams, where you will implement two different sorting algorithms: insertion sort and selection sort. These sorting algorithms, along with `std::sort` from the `<algorithms>` C++ library, will replace  `max_sub_slow`, `max_sub_faster`, and `max_sub_fastest` in your `main()` function from last week's lab.

Things to note about this lab:
1. Be sure to call each of your sorting algorithms on **the same array** for each of the different input sizes.
2. `std::sort` will sort your array **in place** so you must be sure not to attempt sort an already sorted array.
3. This lab has its own starter code, so you should begin with the starter code and copy **the contents** of your `main` function from the previous lab into this lab's `main` function.

## Inputs

A given sorting algorithm may vary in efficiency depending on the type of input. For example, some algorithms sort an already sorted list very quickly, taking advantage of the fact that it is already sorted, while others may take just as long as any other input type. In fact, you will find that all sorts of algorithms have these types of behavior, not just sorting algorithms. This is why we talk about "best case" and "worst case" time complexities. Thus, for this lab, you will run your program on the following types of inputs:

+ Random Unsorted Lists: Use `gen_list_unsorted` to generate your lists
+ Already Sorted Lists: Use `gen_list_sorted`
+ Reverse Sorted Lists: Use `gen_list_reversed`
+ Partially Sorted Lists: Use `gen_list_partial_sort`
+ Unsorted Lists with Few Unique Elements: Use `gen_list_few_unique`

After each time you run your program on one of the above input types, be sure to make note of how each algorithm performs with that input. You will need this information to answer the lab questions.

## Questions/Submission

> **Question 1:** On which type(s) of input did insertion sort perform best? On which type(s) did it perform worst?

> **Question 2:** What was the overall difference between insertion sort's best-case input and its worst-case input? (No need for numbers on this question, just describe the difference the two input types made).

> **Question 3:** On which type(s) of input did selection sort perform best? On which type(s) did it perform worst?

> **Question 4:** What was the overall difference between selection sort's best-case input and its worst-case input?

> **Question 5:** Would insertion or selection sort ever be good sorting algorithms to use in a more general program? Explain your answer.

Once you have finished these questions, copy and paste your code for insertion sort into Question 6 field, your code for insertion sort into the Question 7 field, and your output after running your program with either the reverse sorted lists or the partially sorted lists.
