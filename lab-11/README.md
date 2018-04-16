# Lab 11: Indexing Texts with BSTs

Today we will be reading books. More specifically, we will be taking large text files, seperating them into words, and then indexing them using a Binary Search Tree. However, before doing any of that, we must actually implement a Binary Search Tree.

## 1. Tree Functions

You may have noticed by now that we are working with strings in this lab. The tree nodes hold strings, and tree methods will have to interact with strings. In addition to this, each BST node, also has an `int count` which is the frequency of that word. In order to compare strings, you can use the regular [comparison operators](http://en.cppreference.com/w/cpp/string/basic_string/operator_cmp) as the string class has overloads for these operators.

Here are the functions you will be required to implement

<!-- TODO: constructor & destructor -->

<!-- TODO: search() -->

```c++
void insert(string s);
```
This function will insert the word into the binary search tree. If this word is already in the 
tree, the counter for the node will be incremented.

<!-- TODO: remove() -->

<!-- TODO: destroy() -->

```c++
unsigned int treeHeight();
```
This function will return the height of the tree.

## 2. Getting the Books

In your lab folder you will find a script called `getbook.sh`. This is a small bash script that will download three books as `.txt` files, into your lab-09 directory. You can run the script like this, assuming you are in the lab directory:

```bash
$ source getbooks.sh
```

These books are downloaded from Project Gutenberg's book reposistory. The titles include 
* [Alice's Adventures in Wonderland by Lewis Carroll (173k)](http://www.gutenberg.org/ebooks/11)
* [Pride and Prejudice by Jane Austen (709k)](http://www.gutenberg.org/ebooks/1342)
* [War and Peace by graf Leo Tolstoy (3280k)](http://www.gutenberg.org/ebooks/2600)

## 3. Writing your Code

Before we can start indexing words, we will have to preprocess them before inserting them into our BST. In `main.cc` we already have a loop setup with the proper way to read from the standard input.

You will have to fill in both the `removePunctuation` function, and the `toLower` function.

### 3.1 Pesky Punctuation
```c++
void removePunctuation(string *s);
```
This will take in a string and remove any character that is not A-Z, a-z, or 0-9. You should not have to worry about spaces, as the string given will be a single word, with no whitespace. Simply remove everything that isn't a alphanumeric.

*Hint:* You can make another string, then [assign](http://en.cppreference.com/w/cpp/string/basic_string/assign) the original string the contents of the new string using:

```c++
s->assign(new_str);
```

### 3.2 Unruly Uppercase

```c++
void toLower(string *s);
```
This function will be passed a string with only alphanumeric characters. toLower will convert all uppercase characters to lowercase. Digits can be left untouched.

To compile use:

```bash
$ g++ -std=c++11 -g main.cc bst.cc -o reader
```

### 3.3 Running Code

To run it, use either 

```bash
$ debug50 reader < alice.txt 
```

or,

```bash
$ ./reader < alice.txt
```

Your asserts should pass the section for 'parsing functions'
but will most likely not work well.

## 4. Statistics of the Tree

In addition to the above, you will have implement your own public methods, and private helper methods to accomplish the following. You may want to consider using tree traversals:

* Get the height of the tree. For this one, you can use `treeHeight()`.
* Get the total number words in the book, including repeats. (You must use the tree, not a counter in the while loop in main.cc)
* Get the total number of distinct words. (Don't count repeats)
* Get the most frequent word
* Print out any word that only occurs once.

*If you see strange words in your books, such as 'email' in Alice's Adventures in Wonderland, it is probably part of Project Gutenburg's license information. For this lab, we will consider them to be part of the book.*

## 5. What to Submit

The google form for submitting can be found at [here.](https://docs.google.com/forms/d/e/1FAIpQLScKmAYjsGLEKsNXbOhjc-wszyEKUJP5uJyD4N848tJP9FRM-g/viewform?usp=sf_link) The instructors will inform you when the link is active.

You will need to submit the source code for your bst.cc. After that, there are three questions to answer:

* *What is the height of all three trees?*
* *How many words are there in Alice's Adventures in Wonderland? (Including the copyright information at the beginning of the file)*
* *How many distinct words are there in Pride and Prejudice?*
* *What is the most frequent word in War and Peace?*
