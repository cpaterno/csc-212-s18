# Lab 07: Implementing Dynamic Arrays in C++

### Description

This week in class you learned about memory allocation and linked lists. In today's lab you will be implementing a **Dynamic Array**.
The starter code for this lab can be found above (You need the 4 files: **darray.h, darray.cc, main.cc and vtest.sh**). You should work in groups of 2 to 3. 


### Dynamic Arrays

As you know by now, when an array is created in C++ a set amount of memory is allocated for the array to use. For example, both of the following array declarations allocate exactly enough memory to store 6 integers:

```C++
int array_a[6]; // This array on the stack can hold 6 ints
int array_b = new int[6]; // This array on the heap can also hold 6 ints
```

However, in some languages, such as JavaScript, arrays can change size whenever needed. These types of arrays are called **Dynamic Arrays**, and in many situations Dynamic Arrays are much easier to work with. Generally Dynamic Arrays accomplish their resizing behavior by having a capacity variable that represents *the number of elements it is able to store* in its internal array. When an element is being added to a Dynamic Array that can hold no more elements, the capacity is doubled, a new array is created with the new capacity, and all of the elements are copied from the old array to the new array. This new array then becomes the one used by the Dynamic Array.

In addition to having the ability to change size, Dynamic Arrays also tend to provide many methods for accessing and modifying their content, providing further ease of use. In today's lab you will need to implement the following methods for your own Dynamic Array class. The class structure is already provided in `darray.h`.

#### Constructors/Destructors:

+ `DArray()`: A basic constructor to initialize the class' private variables. Your capacity (`cap`) may be initialized as 10.
+ `DArray(int c)`: A constructor similar to the `DArray()`, but with the capacity specified by the parameter `c`.
+ `~DArray()`: A destructor to deallocate the memory used by the class instance when it is destroyed.

#### Helper Methods:

+ `grow()`: A helper method that doubles the size of the internal array when an element is being added to a Dynamic Array that can hold no more elements.
+ `shrink()`: A helper method that does the opposite of grow, reducing the size when the DArray is half full or less.

#### Accessors:

+ `size()`, `capacity()`, `front()`, and `back()`: Accessor methods that return the length, capacity, first element, and last element respectively.
+ `at(int idx)`: Returns the element at index `idx`.
+ `empty()`: Returns whether or not the Dynamic Array has no elements.

#### Modifiers:

+ `set(int elem, int idx)`: Sets the value of the Dynamic Array at the index `idx` to the value `elem`.
+ `push_back(int elem)`: Inserts `elem` at the end of the Dynamic Array.
+ `pop_back()`: Removes the element at the end of the Dynamic Array and returns it.
+ `insert(int elem, int idx)`: Inserts `elem` into the Dynamic Array at index `idx`.
+ `erase(int idx)`: Removes the element at the index `idx` from the Dynamic Array
+ `clear()`: Resets the length and capacity to their default values.

**Note:** You need to check for valid input in the functions `front()`, `back()`, `at()`, `set()`, `pop_back()`, `insert()` and `erase()`. You should use `assert()` from the library `<cassert>` to abort the program when invalid input occurs. 

## Instructions

Download the 3 files: dll.h, dll.cc, and main.cc

To compile your program, run the following command in your bash terminal:
```
g++ -std=c++11 darray.cc main.cc -o lab8
```
To test your code, run the following command
```
./lab8
```
The above line will test all but your validation checking. To test your validation checking, use the bash script `vtest.sh`. 
In order to run `vtest.sh`, you first need to give yourself permission to execute the file. The `chmod` command is used to edit a user's permissions in linux. If you try to run `vtest.sh` without using `chmod`, you will receive a permission denied error.
```
chmod 777 vtest.sh
```
The command `chmod 777` gives all permissions to everyone for the given file, so you should now be able to execute the script.

To learn more about chmod, [read this page](https://linode.com/docs/tools-reference/tools/modify-file-permissions-with-chmod/) or google chmod.

You will be writing the unimplemented functions in the `DArray` class. You can compile and run the main method in `main.cc` to test the functions as you implement them.


## Using vtest

If you open vtest, you will notice that is a script that compiles `main.cc` and then runs the outputted program with arguments. The argmuents are a counter that iterates up to 11. In `main.cc`, there is a switch case statement that will test different implemented features of your dynamic arrays depending on the argument.

The reason we use `vtest.sh` for validation testing, as opposed to testing everything in one run of the compiled program, is because when a false value is passed into `assert()` the report is printed and the program immediately aborts. Since there are multiple different situations that can cause a false assertion, the program must be repeatedly run to test that each possible failing case does in fact fail. This approach would be tedious, so it is preferable to automate these commands using a Bash script. Thus, learning how to use Bash scripts can make your life a lot easier in the future since they allow easy automation and chaining of Linux commands.

To run vtest, simply run it like any other runnable file.
```
./vtest.sh
```
If you have a permissions issue, make sure you followed the steps above involving `chmod` to give yourself permissions.

**How to read the output of vtest:** When vtest runs, it should output a number and then a message, for the numbers 1 through 11. If the output message starts with `lab8: ` and ends with `failed.` then the method **correctly validates** its input. However, if the message instead is of the form `Method X() failed to validate` where X() is one of DArray's methods, then the method **fails to validate** its input, and must be modified to do so.


## Submission

