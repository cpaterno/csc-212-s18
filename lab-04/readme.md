# Lab 04 (Rough Draft): 

Case study on the complexities of different implementations of Max Subarray Sum:
http://www.ics.uci.edu/~goodrich/teach/cs161/notes/MaxSubarray.pdf

## Introduction

This lab will be completed in teams of three students. Each team will discuss how to solve the problem the lab presents. If a team feels that they have the correct solution they may check with the TA, and if their solution is correct they may show their result to the rest of the class (Just the result, no code).

The goal of the lab is to get a hands-on look at algorithm complexity, which will be accomplished by benchmarking three different implementations of the Maximum Subarray Sum algorithm for different input sizes, and printing a table of the results to the console.

## Compiling

(Info about C++11)

## Benchmarking

Measuring the time an algorithm or a section of code takes to run is called benchmarking. This is how you do it in C++:

```C++
#include <iostream>
#include <chrono>

int main() {
    auto start = std::chrono::steady_clock::now();
    /*
        The part of your code you want to time
    */
    auto end = std::chrono::steady_clock::now();
    
    // This finds the time your code took to run, and assigns it to the variable  t  as a double
    // Now you can use std::cout to print  t  to the console.
    double t = std::chrono::duration<double> (end - start).count();
    return 0;
}
```

## About Maximum Subarray Sum
