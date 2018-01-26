# Lab 02: Arrays, Strings & Functions

## Description

In this lab you will be using arrays to solve various problems. The problems are a selection from Kattis. Below is a quick explaination of arrays, and standard input. Don't forget to register for the session by clicking, "Join Session" at the top right. This is the only way to get credit for the lab. The link to the morning contest is [here](https://uri.kattis.com/sessions/rrccok) and the afternoon is [here](https://uri.kattis.com/sessions/insytp).

Side Note, the standings and timings of you and your classmates solving the problems will be availble publicly. If you do not want your name displayed, there is an anonomyous option in your profile settings. You will still get credit for attendance.

## Arrays

![Arrays](http://beginnersbook.com/wp-content/uploads/2014/01/c-arrays.png)

The first row in this picture is how to reference the cell. The second row is the actual data stored. The third row is the memory addresses of each. This was explained in detail during sections.

To decalre an array:

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
