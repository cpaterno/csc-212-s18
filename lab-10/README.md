# Lab 10: Competitive Programming

This week's lab will be a bit different than usual. Instead of covering a particular programming topic, we will hold a mini programming competition on Kattis. At the start of the first lab section, the link to the Kattis competition will be added to this lab, to prevent any students from getting a head-start. Some additional information about problems that may be vague will be detailed below.

[There still is a google form for the lab.](https://goo.gl/forms/xFww0uoxlLswh4Kp1)

## Kattis

In order to use Kattis, you must sign up for an account. You can create an account by clicking the "Log in" button in the top right corner of the page. There will be an option to sign up for an account. You may use whichever username you like, but we strongly suggeset that you use your first and last names. Once you've signed up for Kattis, you may join the lab's programming competition [here](https://uri.kattis.com) (real link coming soon).

The competitions will be open at the start of the lab session and will last exactly two hours. During this time you should do your best to implement a solution to as many problems as you can (most likely in order, as the problems get progressively harder).

## The Format

**First and foremost, what does competitive programming mean?**

Generally speaking, comptetitive programming involves finding a programmatic solution to a problem given some constraints. These constraints typically consist of a set amount of time during which to code solutions, at the very least, but may also include restrictions on amount of allowed CPU time and memory usage. A code submission is accepted if it implements the solution to the given problem *to specification* (more on this shortly), and it meets all of the given constraints.

**What are the specifications?**

In any competitive programming problem, it is not enough to simply write an algorithm that solves the problem, but it must also be able to read the data in from stdin and write the resulting solution to stdout. Luckily for you, these steps will already have been done for you in the starter code given above, whereas in an actual programming competition this will not be provided.

**So what do we have to do?**

In each starter code file there is an empty function named after the problem with some parameters and a return value. The parameters consist of the input data, put into different variables of appropriate data types for their specific meanings, which will be detailed on a problem-to-problem basis below. These parameters are the data you have to work with for your implementation, and the result returned from your implementation should match the given return type. You should not modify any of the code already provided in the files, but only add code in the provided function.

**How do we submit?**

Once you are satisfied with your solution, you may either upload your **whole file** to Kattis, or copy and paste **all of the code** in the problem file into Kattis by clicking "switch to editor." 

[Also, do not forget to do the google form](https://goo.gl/forms/xFww0uoxlLswh4Kp1)

## Additional Description/Clarification 

*Note: You should read the description for each problem on Kattis before reading the supplementary information here.*

### Problem 0: Stuck in a Time Loop

This problem is simple enough that your solution may be implemented right in the `main()` function. The input number N is already read in, so you must simply print the output specified on the Kattis page.

### Problem 1: Odd Gnome

```C++
int* odd_gnome(int num_groups, int* gs_in_each, int** groups);
```

In this function, `num_groups` is the number of groups of gnomes (i.e., the number of trials), `gs_in_each` is an array of length `num_groups` that contains the number of gnomes in each group of gnomes, and `groups` is an array of int arrays. Each array in `groups` consists of all the gnomes for a single group of gnomes, with length given at the associated index of `gs_in_each`. The function returns an array consisting of the location of the king gnome in each group of gnomes (here counting starts at 1).

### Problem 2: Tarifa

```C++
int tarifa(int X, int N, int* P);
```

Here, the variable names are relatively straigtforward, as `X` and `N` correspond directly to the X and N in the problem description, and `P` is the array of all P<sub>i</sub>, as also described in the problem description. The function will return the amount of megabytes available at month N + 1 of using the data plan.

### Problem 3: 2048

```C++
int** _2048(int** board, int move);
```

Once again, the variables here are relatively straigtforward. The variable `board` is a 4x4 2D array representing the state of the 2048 board read into the program, and `move` is a number between 0 and 3 describing the move to be made: 0 for left, 1 for up, 2 for right, and 3 for down. The function then returns another 4x4 2D array consisting of the board's state *after* applying the move. Note, board need not be modified in any way, so long as the function returns a 2D array that is allocated on the heap and represents the solution to the problem.

### Problem 4: Mancala

As this problem itself may seem a bit confusing, we first try to clarify it here. First of all, there are many different ways to set up a game, and potentially multiple different ways to play given a certain setup, where each setup always starts with the Ruma empty and some number of bins containing counters (we set the limit at 80). However, the task here is not to write an algorithm that plays the game, nor is it to write an algorithm that determines if a given board is winnable. The task here is to find the *unique board* that is capable of being played and won for a given number of counters. The major game rule here is that in your starting board, you may choose any bin that contains a number of counters equal to the bin's number, and place one counter into each lower bin, all the way to the Ruma. If there is a way to choose bins in this way until all the counters are in the Ruma, then that board is a winning board. As for the function signature...

```C++
int* mancala(int count, int* boxes_filled);
```

Here, `count` represents the number of counters that would need to end up in the Ruma when the game is won. In other words, it is the total number of counters in all the bins, and it uniquely identifies a starting board state. The variable `boxes_filled` is actually a *single integer passed by reference,* which will be assigned the number of bins that were used in forming the starting board (i.e., the bin number of the rightmost non-empty bin). Once the algorithm is complete, the function returns an array of integers consisting of the number of counters in each bin, where the bins start counting at 1.

### Bonus Problem: Islands in the Data Stream

If you've enjoyed solving these programming problems thus far, you are encouraged to attempt this bonus problem, either in your free time or in whatever time you may have remaining in the lab. The goal here is laid out relatively well in the description on Kattis [here](https://open.kattis.com/problems/islands).

```C++
int count_islands(int* sequence, int start, int end);
```

This function takes three parameters: `sequence`, `start` and `end`, where `sequence` is the array of 12 numbers in which you must find all of the islands, `start` is the index of sequence to start at and `end` is the index of the sequence to end at. For a small hint, these two index variables imply a recursive solution to this problem. However, if you feel comfortable with modifying the starter code a bit, you may also attempt to find an iterative solution. The function returns a count of the number of islands in the sequence, given the definition of an island specified on the Kattis page.

## Submission

Although you will mainly be working with Kattis for this assignment, you will be required to fill out the Google Doc linked at the start of the lab, just as with any other lab. For this lab you will need to include your Kattis username, along with your implementations (or partial implementations) of each of the problems given above. If you do not get the chance to attempt a problem, you may put just the empty function definition into the problem's associated field.
