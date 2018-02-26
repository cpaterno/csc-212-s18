# Lab 06: Lab + Recursion(6) = Lab + (Lab + Recursion(5))

Today you will be implementing a few recursive algorithms. The neat thing about recursion is that you can solve problems with a relatively small amount of well thought out code. 

The google form for submitting can be found [here.](https://goo.gl/forms/8ouzJARdNmOrgV1K3) The instructors will open the form at the start of the lab session.

## A Quick Review of Recursion

In its simplest form, recursion is just the act of calling a function within its own function body, but such a simple idea can lead to some very elegant and important algorithms. When a recursive function is first called (by a function other than itself) it begins to execute its statements just like any other function. However, when the program reaches the line in which the function calls itself, a new "instance" of the function is created, with whatever new parameters were passed in. This new instance will likely reach a point where it calls itself again, creating yet another new instance...

At first, this may seem like an infinite loop of sorts, but if the function is implemented correctly, the input size should get smaller and smaller on each call. This allows for what we call a base case, which is when the recursive function receives an input so small, that it handles the input non-recursively and then returns to whatever instance of the function last called it.

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

From this you can see that recursion is fundamental to the problem, as the GCD algorithm we have just defined invokes itself for certain inputs.  Your job is to implement the GCD algorithm and time your function as you did in the previous question.

>You will **report** the actual running time of calling your function with the following pairs of values: _(100,612), (1098,8721), (10872,17238), (1000000000,100000000), (184729384, 2273652)_.  Include your intuition behind the running time of this function (constant? linear? logarithmic? quadratic? ...).


## 3. Recursive Fractals

For this problem, you will be playing with fractals.  The term fractal was coined by Benoit Mandelbrot in "The Fractal Geometry of Nature."  He defines a fractal as "a rough or fragmented geometric shape that can be split into parts, each of which is (at least approximately) a reduced-size copy of the whole."  Although you can later read on more complicated [patterns](http://natureofcode.com/book/chapter-8-fractals/), today you will write a program to generate the drawing below:

<img src="./big.2.png" width="600">

Your program will take a positive integer _d_ as a **command line argument** and output to the `stdout` the line segments that compose your fractal (one per line).  Each segment should be expressed as four values, _x1, y1, x2, y2_ that represent the segment connecting _x1,y1_ to _x2,y2_.  You can consider that your fractal will be drawn on a canvas of height=500 and width=500.

The positive integer _d_ indicates the depth of the drawing, in other words, the depth of the recursion.   Listen to the instructor's explanation before getting started.

For example, if your program is called with _d=0_, your output should be empty.  If the program is passed _d=1_, your output should have 4 line segments (the order of the segments does not matter, see example below).  if your program is passed _d=2_ your output should contain 20 segments, and so on.

```bash
$ ./prog 1
125 125 375 125
375 125 375 375
375 375 125 375
125 375 125 125
```

You can actually visualize your fractal by using the `python` script provided.  All you need (after your program is compiled) is run the following line:

```bash
$ ./prog 4 | python create_fractal.py > fractal.html
```

The command above is running your program with depth 4 and piping the output of your program to the python script.  After the python script is completed, its output is redirected to a file named `fractal.html`.   All you have to do at this point is open `fractal.html` inside your browser.  If you are using CS50 IDE, then you can right-click on `fractal.html` and choose `Preview`.

>You will **report** the source code of your program.
