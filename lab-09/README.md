# Lab 09: Singling Out Linked Lists

In this lab, your job is to implement your own singly linked list.  The goal of this lab is to give you a deeper understanding of the linked list data structure that you have been learning about.

[Here is the google form.](https://goo.gl/forms/LWGwepMPYCwimVOw1)

### Visual Aids

Linked list. Contains data and a pointer to the next node.

![image](http://www.java2novice.com/images/linked_list.png)

Pictoral representation of adding a node to a linked list.

![image](http://www.java2novice.com/images/sll_insert_after.png)

Pictoral representation of removing a node from a linked list. Notice how the pointer just skips over the removed node.

![image](http://www.java2novice.com/images/sll_delete_after.png)


## 1. Implementing `LinkedList`

The first section of this lab requires you to implement your own custom linked list class.  In `linkedlist.h` you will see the class definitions for `Node` and `LinkedList`.  You should inspect but not modify this file.  Write all your code in `linkedlist.cc`.  Note that methods for the class `Node` are already implemented and will be used by `LinkedList`.

The class definitions for `Node` and `LinkedList` are shown below:

```C++
class Node {

	private:
		Node* next;
		int data;

	public:
		Node(int d);
		~Node();

	friend class LinkedList;

};

class LinkedList {

	private:
		Node* head;
		Node* tail;
		unsigned int n_elem;

	public:
		LinkedList();
		~LinkedList();

		void insertAt(unsigned int index, int d);
		int removeAt(unsigned int index);

		bool find(int d);
		void append(int d);
		void prepend(int d);
		int removeLast();
		int removeFirst();
		unsigned int getSize();
		void clear();
		void print();

};
```

### 1.1 Constructor and Destructor
For the constructor `LinkedList()` your code should create an empty list and set private variables accordingly.  The `head` and `tail` properties should be set to `NULL` and `n_elem` should be set to 0.

The destructor `~LinkedList()` is a little bit more complicated.  For this method, you must traverse the list and delete each `Node`, so that you don't cause a memory leak.

### 1.2 `void append(int d);`

This method should create a new `Node` and add it to the end of the list.

### 1.3 `void prepend(int d);`

This method should also create a new `Node` but instead of adding it to the end of the list, it should be added to the beginning.

### 1.4 `void insertAt(unsigned int index, int d)`

This method should construct a new `Node` from `data` and insert it into the list at `index`.  _Note_ Indexing starts at 0.

> Methods `append`, `prepend`, and `insertAt` do not return any values.  Also all such methods should increase `n_elem` by 1.

### 1.5 `int removeFirst();`

This method should remove the first element from the list.

### 1.6 `int removeLast();`

This method should remove the last element from the list.

### 1.7 `int removeAt(unsigned int index)`

This method should go to the `Node` at position `index` and remove it from the list, while still preserving the list structure, ie. the previous `Node` before the `Node` at `index` should be linked to the `Node` after the `Node` at `index`.  

> Methods `removeFirst`, `removeLast`, and `removeAt` return the data contained in the node removed from the list.  Also all such methods should decrease `n_elem` by 1.

### 1.8 `unsigned int getSize();`

This should simply return how many elements are in your list.

### 1.9 `void clear()`

This method should remove all nodes from the list, so that the list becomes empty and both `head` and `tail` point to `NULL`.  Also, `n_elem` should be set to 0.

### 1.10 `bool find(int d)`

This method needs to search the list for `data` and returns `true` if `data` is in the list, and `false` otherwise.

### 1.11 `void print()`

This method is provided for you, and may be used to debug your code. It prints all the elements of the linked list and their indices in order, provided the linked list is connected properly. The form of the output is `index:value`, and the final two lines print the values in head and tail if they are not `NULL`. If the linked list is not connected properly, this function will likely have unexpected behavior, and may run into an error or an infinite loop.

*Note: Students to not need to validate their methods*

## Useful Hints/Tips/Edge Cases

+ There are a few common mistakes that can be made when implementing this lab. Make sure that you have cases for the head and tail nodes in the linked list. The head and tail will need to be handeled in some of the methods to make sure that the structure of the linked list stays correct, so always think about how they will be affected by your code.

+ It may be useful to call some of the methods within some of the other methods in order to write less code and simplify some of your implementations.

+ Make note of situations in which the list is empty, and make sure that your code can handle an empty situation if the method permits it (e.g., you can add to an empty linked list, but not remove from one).

## 3. Questions

1.  What is the running time(in big O notation) of your LinkedList::append()?
2.  What is the running time(in big O notation) of your LinkedList::prepend()?
3.  What is the running time(in big O notation) of your LinkedList::removeLast()?

### 2.1 Google Form

[Google Form](https://docs.google.com/forms/d/1ZjCythG0R3Ytb4dhpSS2ZlgLMO5gkMZv8B9ZfBorIaY/edit)
