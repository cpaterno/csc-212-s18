# Lab 06: Lab + Recursion(6) = Lab + (Lab + Recursion(5))

Today you will be implementing a few recursive algorithms. The neat thing about recursion is that you can solve problems with a relatively small amount of well thought out code. 

The google form for submitting can be found [here.](https://goo.gl/forms/8ouzJARdNmOrgV1K3) The instructors will open the form at the start of the lab session.

## A Quick Review of Recursion

In its simplest form, recursion is just the act of calling a function within its own function body, but such a simple idea can lead to some very elegant and important algorithms. When a recursive function is first called (by a function other than itself) it begins to execute its statements just like any other function. However, when the program reaches the line in which the function calls itself, a new "instance" of the function is created, with whatever new parameters were passed in. This new instance will likely reach a point where it calls itself again, creating yet another new instance...

At first, this may seem like an infinite loop of sorts, but if the function is implemented correctly, the input size should get smaller and smaller on each call. This allows for what we call a base case, which is when the recursive function receives an input so small, that it handles the input non-recursively and then returns to whatever instance of the function last called it. From there each previous function will return (perhaps after doing some processing) until the original call returns and the recursive function has completed. However, if the function is not implemented with a base case, or continually recurses without reaching one, the program will crash with a stack overflow error.

Below are some visual aids to help in understanding recursion.


### Visual for how to think about recursive function calls
![image](https://i.imgur.com/Z5eeHrE.png)


### Visual showing how a factorial recursive function works. Example is factiorial(5)
![image](https://i.imgur.com/HAgjJlu.gif)

### Fibonocci Sequence Visualized
![image](https://i.imgur.com/rbAZFhN.gif)

### Recursivly finding the length of a list
![image](https://i.imgur.com/ByMc0mX.gif)


## 1. Sum of Numbers

For the first problem, you will implement the sum of numbers up until _n_. The header for this function will be

```c++
unsigned long int sum(unsigned int n)
```

If the input is `10`, your function should calculate `10+9+8+7+6+5+4+3+2+1`, which should equal `55`.  This must be done recursively (no loops).

### Running the Code

You will create a small program `sum.cc` and time the execution of your function.  See the example below:

```c++
#include <chrono>
#include <iostream>

int main() {
    auto start = std::chrono::steady_clock::now();
    // call your function here
    auto end = std::chrono::steady_clock::now();
    
    // print the elapsed time
    std::cout << std::chrono::duration<double> (end-start).count() << " seconds" << std::endl;
}
```

Then compile your program using the command below:
```bash
$ g++ -std=c++11 -g -Wall sum.cc -o sum
```

>You will **report** the actual running time of calling your function with the following values: 1000, 10000, 100000, 1000000, 1000000000.  Include your intuition behind the running time of this function (constant? linear? logarithmic? quadratic? ...).


## 2. Greatest Common Divisor

The Euclidean algorithm is a computationally efficient way to find the greatest common divisor between any two numbers.
The greatest common divisor of _a_ and _b_ is the largest number that will divide evenly into both _a_ and _b_.
For example, _GCD(81,96)_ is _3_ because _3_ is the largest number that will divide _81_ and _96_ with no remainder.  The algorithm can be formulated as follows:

```python
GCD for any a, b:
    if b is larger than a:
        swap a and b
    if a is equal to b:
        a is the GCD of a and b
    otherwise apply GCD(a-b, b)
```
Here is the wikipedia on GCD in a recursive context. Use it as a resource if needed https://en.wikipedia.org/wiki/Recursion_(computer_science)#Greatest_common_divisor


From this you can see that recursion is fundamental to the problem, as the GCD algorithm we have just defined invokes itself for certain inputs.  Your job is to implement the GCD algorithm and time your function as you did in the previous question.

>You will **report** the actual running time of calling your function with the following pairs of values: _(100,612), (1098,8721), (10872,17238), (1000000000,100000000), (184729384, 2273652)_.  Include your intuition behind the running time of this function (constant? linear? logarithmic? quadratic? ...).


## 3. The Natural Numbers

The set of all integers greater than 0 (i.e., {1,2,3,4,5,...}) is commonly referred to the set of natural numbers. Write a recursive algorithm that takes a positive integer input _n_ and prints out all of the natural numbers from 1 to n. The function signature for this problem should be as follows:

```C++
void print_nums(unsigned int n);
```

You may print all the numbers on one line separated by spaces, or each number on its own line, but these are not very elegant for large values of _n_. For brownie points, start printing your output on a new line after every 10 numbers. Your expected output will then look similar to this:

```
1 2 3 4 5 6 7 8 9 10 
11 12 13 14 15 16 17 18 19 20 
21 22 23 24 25 26 27 28 29 30 
31 32 33 34 35 36 37 38 39 40 
41 42 43 44 45 
```


## 4. The Fibonacci Series
Test Data : 
Input number of terms for the Series (< 20) : 10
Expected Output :

 Input number of terms for the Series (< 20) : 10                                
 The Series are :                                                                
 1  1  2  3  5  8  13  21  34  55  
 
## 5. Number of Digits
Test Data : 
Input a number : 50 
Expected Output :

The number of digits in the number is :  2

Paste your code into the google form.
