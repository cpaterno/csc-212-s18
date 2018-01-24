# Lab 01: C++, Docker, and CS50, oh my!

> **IF you ALREADY HAVE docker installed skip [1. Installing Docker](https://github.com/URI-CSC/csc-212-f17/blob/master/lab-00/readme.md#1-installing-docker), and go to ['2. Cleaning a Docker Installation'](https://github.com/URI-CSC/csc-212-f17/blob/master/lab-00/readme.md#2-cleaning-a-docker-installation-optional-for-fresh-installs)**

## 1. Installing Docker

### 1.1 Downloads

>If you have have _Windows 10 Pro or macOS 10.10.3+_, you can install Docker from the website [Docker Download Page](https://www.docker.com/community-edition#/download)

>If you DO NOT have _Windows 10 Pro or macOS 10.10.3 and above_, you need to install the [Docker Toolbox](https://www.docker.com/products/docker-toolbox).

If you are running linux, you don't actually need docker. You can run and compile everything in your terminal using shell commands. If you would like to try something new and exciting, all instructors can help with bash commands and vim shortcuts. This class will use g++ as a compiler. 

HOWEVER, Docker allows for the use of the [CS50 IDE Offline](https://manual.cs50.net/ide/offline).  This is the IDE that we will show examples in and as instructors we will be able to provide the best support to students who use this IDE. It includes the same compilers that we will be using as instructors and should make your experience easier in general.

Additionally, there is a high likelyhood that you will use docker in the future. If would like to install docker select your distribution of linux, then click on community edition (CE) [Linux Docker.](https://docs.docker.com/engine/installation/#server) The linux installation differs from Windows and Mac, so feel free to skip over [1.3 Installing Docker](https://github.com/URI-CSC/csc-212-f17/blob/master/lab-00/readme.md#13-installing-docker).

### 1.2 Documentation

Take a second to gloss over your corresponding page for information about docker, and short installation tutorial.

- [Windows 10 Docker documentation](https://docs.docker.com/docker-for-windows/)
- [Mac 10.10.3+ Docker documentation](https://docs.docker.com/docker-for-mac/)
- [Docker Tookbox documentation](https://docs.docker.com/toolbox/overview/)

Once you have been bored out of your mind with these pages, you may then proceed to look at some docker commands, and some information on how docker works.

- [Docker Information / Cheat Sheet](https://github.com/wsargent/docker-cheat-sheet#containers)

### 1.3 Installing Docker

Run the Docker or Docker Toolkit installer. 

If you are using the Docker Toolkit make sure to install everything (git, VM, etc), and it should be a straightforward setup.

If you are not using the Docker Toolkit, you must open your shell application. On Windows you may open your command prompt by typing, `cmd` in your search bar and hitting enter. On MacOS, you may use finder to look for an application called, "Terminal".

After installation using either the basic Docker or Docker toolkit installers, open Docker and wait for it to initialize.  Once Docker has finished initializing the command line should begin with a single `$`. __When copying the commands, do not copy the $__ Test your installation by typing:

```bash
$ docker -h
```
 on the command line.  You should see the command help, the last line of output should be 'Run docker COMMAND --help for more information on a command.'.

## 2. Cleaning a Docker Installation (Optional for fresh installs)

__If you have just installed docker above, you should not have to complete the steps below. It won't hurt to do them though__

If you took this class last semester specifically, and have the cs50ide Installed, we ask that you remove it using the commands below.

So here's the verdict if you are using docker for other classes or personal projects, __DO NOT__ run these commands. They will delete all of your containers and images. If this situation applies to you, use the commands `docker image ls` also `docker container ls` to find old data. Then use `docker rmi [images]` and `docker rm [containers]` to remove each unused one individually.

If you want to wipe everything all in one go. Use these commands:

```bash
$ docker rm $(docker ps -a -q)
$ docker rmi $(docker images -q)
```

## 3. Installing the IDE:

In this class we will be using the cs50ide, kindly provided [here](https://manual.cs50.net/ide/offline). Run Docker and paste the following:

```bash
$ docker run --privileged --name cs50ide -d -p 5050:5050 -p 8080:8080 cs50/ide50-offline
```

### 3.1 Ensuring cs50ide is running:

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

### 3.2 Important Notes:


1. At this point you may notice a banner along the top of your window noting that your current version is out of date, you're welcome to update now, though it won't make any difference for this lab. To update, run `update50` in the built-in shell, which should be titled 'workspace/'. You'll then have to restart the docker instance by running `docker restart cs50ide` **Please note that this name may be different than the one the IDE will tell you to restart**

2. After restarting docker or your computer, you will no longer be able to connect to the IDE using your browser. 
In order to access the IDE again, run Docker and type the following:
```bash
$ docker start cs50ide
```

## 4. Running a C++ program in the CS50IDE

### 4.1 New Interface

You should now be staring at your brand new IDE. Click on 'File', then select, "New File". Here is the basic anatomy of this screen featuring MSPaint.

![Screen shot of the IDE](https://github.com/URI-CSC/csc-212-s17/blob/master/lab-00/anatomy.png "Cloud9 IDE Anatomy w/ MSPaint")

Once you have your new file, you may start typing and wonder why there is no Syntax Highlighting. The way fix this is to save your file as a '.cpp' file. Save your new file now as, 'hello.cpp'. We assume you know how to save files.

### 4.2 Typing it out

Here we will be able write our first program in the file window. Feel free to write your own "Hello World!" program.


```c++
#include <iostream>

int main()
{	
	std::cout << "Hello World!" << std::endl;
	return 0;
}
```

### 4.3 Running your masterpiece

**You MUST save your work before compling and running your code** Doing this will save a walk all the way to the TA office, just to have us save your file for you.

### 4.4 Compiling your code using the bash terminal

Time to put the bash terminal to use. If you have never used a shell, or bash before, do not worry. The first thing we should do is find the files we have avalible to us. Type this into the Bash Shell. The line should start with, `~/workspace/ $ `

```bash
$ ls
```

You should see, `hello.cpp` or whatever you named your file.

Next is to compile your program. We will use `g++`. Simply type this below:

```bash
$ g++ hello.cpp -g -o hello
``` 

`-g` tells the compiler to include debugging symbols which allow you to use breakpoints to debug your code

`-o` tells the compiler that the next argument should be the name of the output file `hello` in this example

If you have any syntax errors they will be printed to you now. Assuming your program successfully compiled, you now have a machine code file called `hello` (or whatever you decided to call the file). You can see this new file by typing `ls` in the bash shell again.

Finally you must run your executable code by typing,

```bash
$ ./hello
``` 

Voila, you have just run, "Hello World!"

### 4.5 Shell Hints

Before we move on, there are a few things about the shell you should know. The up arrow goes to previous commands. And if you think the computer can guess what you are typing, you can hit TAB to have it completed for you. For example, if `g++ hel` is typed in terminal, and the TAB key is hit, the rest of the file name will be filed in.

## 5. Step-by-Step Debugging of "Hello World"

Now you will running your program in debug mode; this mode allows you to run code line by line, or chunk by chunk, depending on where your breakpoints are. While the code is running, you can update variables and function calls, thus allowing you to find errors in your code more easily.

### 5.1 Setting a Breakpoint

Before you start debugging you must set a breakpoint in your code. In debug mode, your program will run normally until it reaches the breakpoint. You are now in control of when your program executes its lines of code. To set a breakpoint, click  on the light gray space in your file window that is to the left of the numbers column, on the line that you wish to start debugging. A big red circle should appear after clicking once, with an example shown below:
![image](https://cloud.githubusercontent.com/assets/16960663/22256982/6a986336-e22a-11e6-8f9a-8cb723ba68a2.png)

### 5.2 Running in Debug Mode

Now that you've set a breakpoint, we must run the program in debug mode. You can do this by running the `debug50` command.  For our example the following will run your program in debugging mode:

```bash
$ debug50 hello
```
![Screen shot of the debug cmd](https://github.com/URI-CSC/csc-212-f17/blob/master/lab-00/debug50.png "Debug Command")

### 5.3 Debugging "Hello World"

You should notice that your program stops executing at the breakpoint, and the line with the breakpoint is highlighted yellow. When debugging, the highlighted line is the next line of code to be executed. To the right you should see the debugging window, as shown below.   

![image](https://github.com/URI-CSC/csc-212-f17/blob/master/lab-00/debugWindow.png)  

The top row of buttons allow you to navigate and execute your code. From Left to Right: The play button, or the resume button, will stop debugging and run your program normally until it reaches another breakpoint, end of program, or a runtime error, and then starts debugging again. The Step Over and Step Into buttons will both execute the next line of code. They perform differently when the next line of code includes a function. The Step Over button will execute the function call completely and finish executing the current line. The Step Into button will instead move the debugger to that function's code and continue debugging there. The Step Out button can be pressed when you are inside a function call to finish the function call and return to the original line of code that called that function. The Deactivate All Breakpoints button is self explanatory.  

### 5.4 Debugging Another Program

It may help to practice debugging another program. Debugging this program will also show how the debugger displays information on the program's variables. 

Create and debug each line of the following program:
```c++
#include <iostream>

int main() {
    int a = 2;
    int b = 4;
    int c = a + b;
    std::cout << c << std::endl;
    return 0;
}
```
You will notice some new information in your debugger window, under Local Variables. Play around with the debugger until you are satisfied. 

## 6. Exercises

>___Please record the answers to the following questions on a separate file.  Your attendance will be recorded after you submit these answers to the Google Form.___

### 6.1: Exercise 1

> If you are not familiar with arrays, read [this](http://www.cplusplus.com/doc/tutorial/arrays/) first.

For this exercise you will create an integer array of 10 elements and print the memory addresses of each element. You can fill the array with any values you like, or leave it empty.  The contents of the array do not matter for this exercise.  The syntax to print the memory address of the 3rd element in an array is as follows: 

```c++
std::cout << &array[2] << std::endl;
```

Remember to print newlines after every value to help readability (`std::endl` or `'\n'`). Make sure to `#include <iostream>` so that you can use `std::cout` to print your results for each exercise.

#### Questions

1. What is the range of the memory addresses of the array?  (Optionally, try changing the size of the array to see what happens)
2. What is the difference between the addresses of two consecutive elements in the array?  Is this constant throughout the whole array?
3. How do these factors change when you declare your array as a `long int` instead of `int`?
4. How do these factors change when you declare your array as a `double` instead of `int`?
5. How do these factors change when you declare your array as a `char` instead of `int`?

### 6.2: Exercise 2

> If you are not familiar with character sequences (strings), read [this](http://www.cplusplus.com/doc/tutorial/ntcs/) first.

For this exercise, you will be creating a character array and use it to investigate C style strings and their behaviors.  Declare and initialize the character array as follows:
```c++
char str[15] = "Hello CSC212";
```
Ensure you use double quotes for this operation.  Your program will be able to tell how long the string is due to the `'\0'` or `null` character inserted automatically by the assignment.  

Write a loop to traverse the string and print out its length (number of characters excluding the `null` character).  You can tell you've reached the end of the string when you find the `null` character (This character is always equal to 0).  

Next, using the same loop print out the value of each character as a numeric value.  You can accomplish that with the following line:
```c++
std::cout << (int) str[counter] << std::endl;
```
#### Questions
1. What is the maximum length of a string you can store in this array? How many bytes long is that?
2. What is the memory address of the null character?
3. What happens if you try to assign a string longer than the max length?  If you are unsure, try it!
4. What do the numeric values printed out when a `char` is cast to an int represent?
5. What happens if you print the contents of the array without making an assignment (initializing the array)?
6. What happens if you print the contents of the array past the `null` character?

## Google Form submission
[Form Link](https://goo.gl/forms/jw55Kxq8f7oPn9bs2)
