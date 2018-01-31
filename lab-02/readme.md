# Lab 02: Arrays, Strings & Functions

As you work on the lab, make sure to answer the questions for the [google form](#).

## Description

In this lab you will be using arrays to solve various problems. Below is a quick explaination of arrays, and how to read data from the standard input (`stdin`). 

We will be running and executing code in the lab, so we will need to have the IDE running through docker.

You will find the file (starter code) that this lab refers to above, named `lab2.cc`. You should either copy or upload this file into cs50ide to follow along with the lab.

## Arrays

In computer science, an array type is a data type that represents a collection of consecutive elements (values). 

To declare (create) an array in C/C++ you will need to provide the data type and size:

```C++
type name[size];
```

Consider for exmple creating an array of six integers:

```C++
int val[6];
```

The figure below shows a memory representation of the array `val`.  First row in this picture shows the indices used to reference single elements in the array. The second row shows the actual data stored. The third row shows the memory addresses of each data element. This was explained in detail during sections.

![Arrays](http://beginnersbook.com/wp-content/uploads/2014/01/c-arrays.png)

> ***Question 1:*** Write the code to create an array of type double that can fit 500 doubles inside it.

## Standard Input Examples

### Example 1
Suppose your input is described as a set of test cases. Each test case is one line of input, which begins with an integer **n**, and is followed by **n** integers which make up the sample to work with. 

**Example Input:**
```
3 6 3 5
6 2 7 6 3 2 9
7 10 4 1 2 5 8 7
2 3 6
```
We will begin by handling the first line of input. 
We first want to read the first integer in the line and store it into a variable **n**. Using *std::cin* we have the following:
```C++
int n;
std::cin >> n
```
In the example input, **n** would be *3*. In this example we will be storing the portion of the input that we want to work with into an array. Since we know this test case has **n** amount of inputs (*3* in this case), we will read from the line **n** (or *3*) more times. 
```C++
int sample [100];                // Assuming a maximum size of 100
for (int i = 0 ; i < n ; i++) {  // Reading from standard input n number of times
    std::cin >> sample[i];
}
// Do something with n and your sample array
```
The array **sample** in this example ends up being *[6,3,5]*.

Now this is how you read one line of input from this example. We want to do this process for as many lines of input as we are given. We modify the second line of our code using a **while loop** to be able to read numbers for as long as there is more input to be read from the next line. Our code finalizes to the following.

```C++
int n;
while (std::cin >> n) {
    int sample [n];
    for (int i = 0 ; i < n ; i++) {
        std::cin >> sample[i];
    }
    // Do something with n and your sample array
    // Which will change with each passing of the while loop
    // ... or each line of input
}
```
	
### Reading an Unknown amount of input

What if a problem poses to you input that is separated by spaces, and then seperate test cases by lines?

```C++
int main() {
    std::string input;
    while (std::getline(std::cin, input)) {
        std::istringstream iss(input);
        int integers[32];
        int n = 0;
        while (iss >> integers[n]) {
            n++;
        }
        // Setup ends here
        // n = number of elemends in the array of integers
        // integers = array that you must find the member of the list
        // that is the sum of all other integers in the list
    }
}
```

## Strings

A `char *`, (character pointer) is a data-type that is used as a string in C. The `char *` points to the memory address of the first letter in the string. You can find out the contents of a string just by having the address of the starting letter since the end of a string is always a '\x0' or `0`, so you have the start and the end.

Strings are actually one-dimensional array of characters terminated by a null character '\x0'. Thus a null-terminated string contains the characters that comprise the string followed by a null.

The following declaration and initialization create a string consisting of the word "Hello". To hold the null character at the end of the array, the size of the character array containing the string is one more than the number of characters in the word "Hello."
```C++
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```
If you follow the rule of array initialization then you can write the above statement as follows −
```C++
char greeting[] = "Hello";
```
Following is the memory presentation of the above defined string in C/C++ −

![Strings](https://www.tutorialspoint.com/cprogramming/images/string_representation.jpg)

Actually, you do not place the null character at the end of a string constant. The C compiler automatically places the '\x0' at the end of the string when it initializes the array. Let us try to print the above mentioned string −

```C++
#include <iostream>

int main () {

   char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\x0'};
   std::cout << "Greeting message: " << greeting << std::endl;
   return 0;
}
```

> **Question 2:** Running the code above. What is the message that is printed?

> **Question 3:** What character in the array lets the program know that it has reached the end?

> **Question 4:** Imagine a character array of the word "Chuck's". If the memory address of the first 'C' is 0x14250, what is the memory address of the 'k'?

> **Question 5:** Looking at the code below, what would the variable 'length' need to be in order for the code to work properly?

```C++
int main () {
    int length;
    char message[] = "Tide Pods are not food";
    char message2[length] = {'T','i','d','e',' ','P','o','d','s',' ','a','r','e',' ','n','o','t',' ','f','o','o','d','\x0'};
    return 0;
}
```

> **Question 6:** How long of a word could fit inside of the char array named letters (shown below)?

```C++
int main () {
    char letters[20];
}
```

> **Question 7:** Would this code work? If it works, why does it work? If it doesn't work, what would need to be changed?

```C++
int main () {
    char game[8] = "fortnite"
    return 0;
}
```

## Functions

When writing programs, particularly ones that are large and complex, or have to carry out many different tasks, it is often unwieldly and impractical to try to write all of your code just in main(). One of the most common and most powerful solutions to this problem is the use of functions. If you already feel you understand the basics about functions in C/C++, you may skip to **Passing by Value vs by Reference**.

### Definition and Declaration

On the most basic level, functions are blocks of code that can be used over and over, almost anywhere in your code. Here is an example function that prints out "Hello world!":

```C++
void say_hello() {
    std::cout << "Hello world !" << std::endl;
}
```
Just having this bit of code in a file is not enough to actually print "Hello world!" though. That's because the above code is a **function definition**, which just states what a function should do when used. In a function definition, everything that comes before the function block is called the **function declaration** or **function prototype**. In this case the prototype is `void say_hello()`. It tells the compiler about a function's name, return type, and parameters.

In order to use a function, we provide the function's name and parameters. For example, we could use this statement somewhere in our code:

```C++
say_hello();
```

When we do this, we say that we **call** the function. A function can be called from inside another function, (and even inside itself, but that's for a later day), but it must be **declared** in the code before it can be called.

A function declaration is essentially the same as a variable declaration: it tells the program that a function exists, even if it hasn't been defined yet. This allows the function to be defined after it is used somewhere else in the code. One situation where this may be helpful is when you have two different functions that need to call each other.

It's also worth noting that `main()` is a function. In fact, it is a special function in C (and C++), as it is needed in every C program and is always called before anything else when the program starts.

**A quick word about scope:** If you have some variables in your main function, say `foo` and `bar`, and you try to use or change their values in some other function, you will probably get an error. This is because variables in one function are separate from variables in other functions, and so cannot be accessed outside of their own function.

### Passing and Returning Values

While having a quick and easy way to print "Hello world!" to the console at any time is pretty cool, it's not the most practical piece of code. We know that we cannot access a variable outside of the function block, so how can we use functions to actually make meaningful changes to our code? We do this by using parameters. Consider the following function:

```C++
int add(int num1, int num2) {
    int sum = num1 + num2;
    return sum;
}
```

This function has two important new parts to it, the variables between the parentheses and the `return` statement. The variables between the parentheses of a function are the **parameters** to the function, i.e., the values that are taken as input when the function is called. Likewise, the `return` statement represents the output of the function.

You may have noticed that this function starts with `int` instead of `void`. This is because when a function is declared, it must start with the data type that it will return after being called. Since the first function did not return anything, its definition began with `void`.

Consider this function call `add(3,4)`. Here we say that the values 3 and 4 are **passed** to the function. Thus when `add` runs, `num1` and `num2` get the values 3 and 4 respectively. Alternatively, 3 and 4 could be variables defined within the body of the main function. When the function reaches the return statement, the function is returned, and the function call gets the value that was returned. So `add(3, 4)` becomes equivalent to the returned value `7`.

### Passing by Value vs by Reference

It turns out there are actually two ways to pass data to a function, **by value** and **by reference**. The difference is in what happens to variables when passed to a function. When a function passes a variable by value, the value stored in the variable is copied into the function's parameters. In this way, when functions are returned, the variables passed to them remain the same. This is the default way of constructing and calling functions in C++.

On the other hand, you can define a function to pass by reference. When a function passes a variable by reference, it will "link" the passed variables to their corresponding parameters in the function for the duration of the function call. The effect of this is that any changes made to the parameter variables in the function body will actually change the corresponding variable in the function call in the same way.

A function call that passes by reference is actually defined and called slightly different from a function called by value:

```C++
int subtract_five(int *num1) {
    *num1 -= 5;
}
```

```C++
subtract_five(&a);
```

As shown above, a variable defined to be passed by reference has the **\*** symbol before any use of the parameter variable (in the function header **and** the body). In addition, the variable passed in the function call is preceeded by the **&** symbol. Understanding the reason for this requires knowledge about pointers, the next lab's topic, but for now it's enough to just know that it works.

In the starter code provide, line `28` calls `add`, passing it the variables `a` and `b`. If you set a breakpoint there, compile the program, run it using `debug50`, and step over once, you will see that `a` and `b` are still the same. You should now be on line `31`, which calls `subtract_five` on `a`. Step over once more, and now `a` has changed to five less than its original value.

Note: A function call need not pass all variables in the same way. Sometimes you may want a function that passes some variables by value and some by reference, which is completely fine. Just remember that parameters passed by value are in the form `foo` and those passed by reference in the form `*foo`.

> **Question 8:** What would the function signature of the code block shown below look like, assuming all variables that aren't declared in the block are parameter variables? Are there multiple options for any of the data types?

> **Question 9:** What would a call to this function look like, with variables `a` and `b` passed in order? What changes to `a` and `b` would occur, if any?

```C++
/* Function signature goes here */ {
    int result;
    x --;
    (*y) ++;
    result = x - *y + 4;
    return result;
}
```

### Final Questions/Exercises

The intersection of two sets (where a set is essentially an array without duplicates) is the set of all items found in both sets. For example, the intersection of the sets (1,2,3,4,5) and (1,3,5,7,9) is the set (1,3,5). In C, intersection also works with strings, as each char in a char array has a numerical value, allowing for mathematical comparisons.

> **Question 10:** Create a function that performs an intersection between two strings (char arrays), each with a max length of 10 characters (not including the null character). We will assume all input arrays are acting as sets, and thus have no duplicate elements. You may use the file `intersect.cc` at the top of the page as your starting code. If your implementation functions properly, the output of the program should be as shown below. Again, copy and paste the code into the answer box once completed.

```
~/workspace/ $ ./intersect
bdehi
deh
therd
```

On the other hand, the union of two sets is a set containing all elements of **both** sets, with no duplicates. For example, the union of (1,2,3,4,5,6) and (3,4,5,6,7,8,9,10,11,12) is (1,2,3,4,5,6,7,8,9,10,11,12), and the union of (A,B,C,D,D,F) and (A,B,G,H,J) is (A,B,C,D,F,G,H,J). Notice how they were combined but the parts they both had were not duplicated.

> **Question 11:** Create a function that performs a union between two strings that are a maximum of 10 characters long. The function may use the same parameters and return type as the intersection problem, but will this time return the union instead of the intersection. Once done, copy and paste the code into the answer box.
