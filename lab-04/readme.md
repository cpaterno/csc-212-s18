# Lab 04: 

Case study on the complexities of different implementations of Max Subarray Sum:
http://www.ics.uci.edu/~goodrich/teach/cs161/notes/MaxSubarray.pdf

## Introduction

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
}
```
