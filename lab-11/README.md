# Lab 11: Indexing Texts with BSTs

Today we will be reading books. More specifically, we will be taking large text files, parsing individual words, and then indexing them using a **binary search tree**. However, before doing any of that, we must actually implement a binary search tree. *You may use any code you've written involving BSTs as a basis for this lab.*

[Per usual, here is a link to the form](https://goo.gl/forms/76B1w5JilZUBMYmj1)

## 1. Tree Functions

For the first part of this lab you will be implementing a binary search tree, using the provided header file `bst.h`. You may notice that, unlike our previous BSTs, we are using `strings` instead of `ints` as keys. This means all the methods you write must deal with `strings`, **not** `ints`. In addition to this, each BST node also has an `int count`, which is the frequency (or number of occurrences) of that word. 

In order to compare strings, you can use the regular [comparison operators](http://en.cppreference.com/w/cpp/string/basic_string/operator_cmp) as the string class has overloads for these operators.

Here are the functions you will be required to implement

```c++
BSTree();
~BSTree();
```
Your typical BST constructor and destructor, `BSTree()` must initialize all of the tree's variables and `~BSTree()` must delete all of the tree's nodes (you may use `destroy()`, as specified below).

For the following four methods (`search()`, `insert()`, `remove()`, and `treeHeight()`) you should use the associated private helper function, which additionally takes a `BSTNode*` as a parameter, to accomplish the algorithm recursively.

```c++
bool search(std::string);
```
This function will search the BST for the given string, returning `true` if the string is found, and `false` otherwise.

```c++
void insert(std::string);
```
This function will insert the word into the BST. If this word is already in the tree, the counter for the node will be incremented.

```c++
void remove(std::string);
```
This function will search for the given string in the BST. If it finds the string, it will decrement the node's counter if it is greater than 1, or delete the node entirely (making any necessary changes to keep the tree a BST).

```c++
unsigned int treeHeight();
```
This function will return the height of the tree.

```c++
void destroy(BSTNode*);
```
This function will delete the entire tree in which the given `BSTNode` is the root. This may be just a subtree, or the entire BST.

Once you have implemented and tested each of these methods, you may continue on to the rest of the lab.

## 2. Getting the Books

In your lab folder you will find a script called `getbook.sh`. This is a small bash script that will download three books as `.txt` files, into your lab-09 directory. You can run the script like this, *assuming you are in the lab directory*:

```bash
$ source getbooks.sh
```

These books are downloaded from Project Gutenberg's book repository. The titles include 
* [Alice's Adventures in Wonderland by Lewis Carroll (173k)](http://www.gutenberg.org/ebooks/11)
* [Pride and Prejudice by Jane Austen (709k)](http://www.gutenberg.org/ebooks/1342)
* [War and Peace by Leo Tolstoy (3280k)](http://www.gutenberg.org/ebooks/2600)

## 3. Writing your Code

Before we can start indexing words, we will have to preprocess them, and insert them into our BST. In `main.cc` there is already a loop to read from the standard input.

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

To run your code execute the following from the terminal:

```bash
$ ./reader < alice.txt
```

To debug your code:

```bash
$ debug50 reader < alice.txt 
```

`main.cc` already has some assert statements, at this point **some should still fail**. 

Carefully read through the asserts, and make sure you are passing up to 

## 4. Statistics of the Tree

In addition to the above, you will have implement your own public methods, and private helper methods **in the tree class** to accomplish the following: 

* Get the height of the tree. For this one, you can use `treeHeight()`.
* Get the total number words in the book, including repeats. (You must use the tree, not a counter in the while loop in main.cc)
* Get the total number of distinct words. (Don't count repeats)
* Get the most frequent word
* Print out any word that only occurs once.

*Hint: You may want to consider using tree traversals*

*If you see strange words in your books, such as 'email' in Alice's Adventures in Wonderland, it is probably part of Project Gutenburg's license information. For this lab, we will consider them to be part of the book.*

## 5. What to Submit

The google form for submitting can be found at [here.](https://goo.gl/forms/76B1w5JilZUBMYmj1) The instructors will inform you when the link is active.

You will need to submit the source code for your bst.cc. After that, there are four questions to answer:

* *What is the height of all three trees?*
* *How many words are there in Alice's Adventures in Wonderland? (Including the copyright information at the beginning of the file)*
* *How many distinct words are there in Pride and Prejudice?*
* *What is the most frequent word in War and Peace?*
