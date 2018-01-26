# Lab 02: Arrays, Strings & Functions

## Description

In this lab you will be using arrays to solve various problems. Below is a quick explaination of arrays, and standard input. 

We will be running and executing code in the lab, so we will need to have the IDE running through docker.

#### Docker Startup
Open docker, for some it will be opening docker toolbox and for others it will be opening a terminal.
Run this command to start up the IDE.
```bash
$ docker start cs50ide
```
##### Next to get access to the IDE:

Type the following in your browser to access the IDE:

> [http://localhost:5050](http://localhost:5050)

or

> [http://0.0.0.0:5050](http://0.0.0.0:5050])

If you installed the Docker Toolbox, the above links may not work. Instead type and enter the following line in the Docker QuickStart Terminal:
```bash
$ docker-machine ip
```
And you will be given the ip address of your local Docker machine. 
In your browser type the ip address you received followed by the port :5050 to access the cs50ide.

For example:
> [http://192.168.99.100:5050](http://192.168.99.100:5050)


## Arrays

![Arrays](http://beginnersbook.com/wp-content/uploads/2014/01/c-arrays.png)

The first row in this picture is how to reference the cell. The second row is the actual data stored. The third row is the memory addresses of each. This was explained in detail during sections.

To declare an array:

```C++
type name[size];
```

An example would be:

```C++
int arr[100];
```

## Standard Input Examples

###Example 1
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
std::cin>>n
```
In the example input, **n** would be *3*. In this example we will be storing the portion of the input that we want to work with into an array. Since we know this test case has **n** amount of inputs (*3* in this case), we will read from the line **n** (or *3*) more times. 
```C++
int sample [n];				//Creating an array of size n
for(int i =0; i < n; i++){	//Reading from standard input n number of times
	std::cin>>sample[i];
}

//Do something with n and your sample array

```
The array **sample** in this example ends up being *[6,3,5]*.

Now this is how you read one line of input from this example. We want to do this process for as many lines of input as we are given. We modify the second line of our code using a **while loop** to be able to read numbers for as long as there is more input to be read from the next line. Our code finalizes to the following.

```C++
int n;
while(std::cin>>n){
	int sample [n];
	for(int i = 0; i < n; i++){
		std::cin>>sample[i];
	}
	
	//Do something with n and your sample array
	//Which will change with each passing of the while loop
	//...or each line of input
```
	
### Reading an Unknown amount of input

What if a problem poses to you input that is separated by spaces, and then seperate test cases by lines? This strange setup strangely coincides with sumoftheothers.
```C++
int main()
{
    std::string input;
    while(std::getline(std::cin, input)){
        std::istringstream iss(input);
        int integers[32];
        int n = 0;
        while(iss >> integers[n]){
            n++;
        }
        //Setup ends here
        //n = number of elemends in the array of integers
        //integers = array that you must find the member of the list
        //  that is the sum of all other integers in the list
       
} 
```

## Strings

Strings are actually one-dimensional array of characters terminated by a null character '\0'. Thus a null-terminated string contains the characters that comprise the string followed by a null.

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

Actually, you do not place the null character at the end of a string constant. The C compiler automatically places the '\0' at the end of the string when it initializes the array. Let us try to print the above mentioned string −

```C++
#include <stdio.h>

int main () {

   char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
   printf("Greeting message: %s\n", greeting );
   return 0;
}
```
Take the code above

## Functions

When writing programs, particularly ones that are large and complex, or have to carry out many different tasks, it is often unwieldly and impractical to try to write all of your code just in main(). One of the most common and most powerful solutions to this problem is the use of functions.

#### Definition and Declaration

On the most basic level, functions are blocks of code that can be used over and over, almost anywhere in your code. Here is an example function that prints out "Hello world!":

```C++
int say_hello() {
   std::cout << "Hello world!" << std::endl;
}
```
Just having this bit of code in a file is not enough to actually print "Hello world!" though. That's because the above code is a **function definition**, which just states what a function should do when used. To actually make use of this function, we must write this statement somewhere in our code:

```C++
say_hello();
```

When we do this, we say that we **call** the function. A function can be called from inside another function, (and even inside itself, but that's for a later day), but it must be **declared** in the code before it can be called.

A function declaration is essentially the same as a variable declaration: it tells the program that a function exists, even if it hasn't been defined yet. This allows the function to be defined after it is used somewhere else in the code. One situation where this may be helpful is when you have two different functions that need to call each other.

It's also worth noting that `main()` is a function. In fact, it is a special function in C (and C++), as it is needed in every C program and is always called before anything else when the program starts.

#### Parameters

