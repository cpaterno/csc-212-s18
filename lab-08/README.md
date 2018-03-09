# Lab 07: Implementing Dynamic Arrays in C++

### Description

This week in class you learned about memory allocation and linked lists. In today's lab you will be implementing a **Singly Linked List**.
The starter code for this lab can be found above (You need the 3 files: **dll.h, dll.cc, and main.cc**). You may work in groups of 2 to 3. 


### Dynamic Arrays

As you know by now, when an array is created in C++ a set amount of memory is allocated for the array to use. For example, both of the following array declarations allocate exactly enough memory to store 6 integers:

```C++
int array_a[6]; // This array on the stack can hold 6 ints
int array_b = new int[6]; // This array on the heap can also hold 6 ints
```

However, in some languages, such as JavaScript, arrays can change size whenever needed. These kinds of arrays are called Dynamic Arrays, and in many situations Dynamic Arrays are much easier to work with. In addition to having the ability to change size, Dynamic Arrays also tend to provide many methods for accessing and modifying their content, providing further ease of use. In today's lab you will need to implement the following methods for your own Dynamic Array class. The class structure is already provided in `DArray.h`.

+ `DArray()`: A basic constructor to initialize the class' private variables. Your capacity (`cap`) may be initialized as 10.
+ `DArray(int c)`: A constructor similar to the `DArray()`, but with the capacity specified by the parameter `c`.
+ `~DArray()`: A destructor to deallocate the memory used by the class instance when it is destroyed.
+ 

## Instructions

Download the 3 files: dll.h, dll.cc, and main.cc

To compile your program, run the following command in your bash terminal:
```
g++ -std=c++11 dll.cc main.cc -o lab6
```
To run your program, run the following command
```
./lab6
```
You will be writing the unimplemented functions in the SLL class. You can run the main method in main.cc to test the functions as you implement them.

The functions you will have to implement are:
+ append(int data)
+ prepend(int data)
+ insertAt(int index, int data)
+ removeAt(int index)
+ deleteAll()
+ Deconstructor

Descriptions of what each function should do can be found in the comments in the source code. 
Once you are done implementating the missing functions and have shown your working program to a TA, you have completed the lab.
