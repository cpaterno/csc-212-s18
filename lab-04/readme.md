# Lab 04: 

Case study on the complexities of different implementations of Max Subarray Sum:
http://www.ics.uci.edu/~goodrich/teach/cs161/notes/MaxSubarray.pdf

## Introduction

This lab will be completed in teams of three students. Each team will discuss how to solve the problem the lab presents. If a team feels that they have the correct solution they may check with the TA, and if their solution is correct they may show their result to the rest of the class (Just the result, no code).

The goal of the lab is to get a hands-on look at algorithm complexity, which will be accomplished by benchmarking three different implementations of the Maximum Subarray Sum algorithm for different input sizes, and printing a table of the results to the console.

## The Starter Code

The starter code for this lab is available in the link `lab4.cc` above. This code contains five functions which you will use: `max_sub_slow`, `max_sub_faster`, `max_sub_fastest`, `gen_rand_list`, and `delete_list`. The first three need not actually be called directly, as the starter code contains a way to call each function from a function array, but you may use them instead if you wish.

## Compiling

Ensure that your terminal is in the same directory as the .cpp or .cc files and then compile your program using the command:           g++ -g -std=c++11 NAMEofFILE.cc -o NAMEofFILE
*Replace NAMEofFILE with the name of the file you are trying to compile* Also notice the -std=c++11 flag
The program should compile without errors.

This program takes no arguments so the command is ./NAMEofFILE

Make sure your program runs without errors before proceeding.

## Benchmarking

Measuring the time an algorithm or a section of code takes to run is called benchmarking. It times the code just like you would do in real life. It looks at the time when the code starts, runs the code, then looks at the time it ends. This is how you do it in C++:

```C++
#include <iostream>
#include <chrono>

int main() {
    // Get the starting Time
    auto start = std::chrono::steady_clock::now();
    /*
        The part of your code you want to time
    */
    // Get the ending time
    auto end = std::chrono::steady_clock::now();
    
    // This finds the time your code took to run by subtracting the end and start times. It assigns it to the variable  t  as a double
    // Now you can use std::cout to print  t  to the console.
    double t = std::chrono::duration<double> (end - start).count();
    return 0;
}
```

## About Maximum Subarray Sum

We talked about Max SubArray Sum in the lecture, but here is a visual to jog your memory.
![image](https://www.geeksforgeeks.org/wp-content/uploads/kadane-Algorithm.png)

The algorithms we are testing the speed of are trying to solve the max subarray problem. It tries to find a section of the array that gives the biggest number if you add up the numbers in that section. The picture above is what the algorithm tries to figure out.

Like anything in life, there are multiple ways of doing the same thing. Some ways are simple and quick, some are complex and take a long time. Hopefully by the end of this lab you have a better sense of algorithm complexity and why it's important to have quick and simple algorithms, especially as the amount of input increases.
