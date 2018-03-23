#include "linkedlist.h"

/*
*  Node Constructor
*/
Node::Node(int d)
{
	data = d;
	next = NULL;
}

/*
* Node Destructor
*/
Node::~Node() 
{
	// No dynamic memory, nothing to deconstruct
}

/*
* List Constructor
*/
LinkedList::LinkedList()
{
	// TODO: Initialize all private data members
}

/*
* List Destructor
*/
LinkedList::~LinkedList()
{
	// TODO: Needs to remove ALL elements from the list
}

/*
* The insertAt function receives an index, and a value
* and inserts it at that index in the list
*/
void LinkedList::insertAt(unsigned int index, int d)
{
	// TODO
}

/*
* The removeAt function receives an index,
* and removes the element at that index
*/
int LinkedList::removeAt(unsigned int index)
{
	// TODO
}

/*
* The find function receives an integer,
* and returns if it is in the list
*/
bool LinkedList::find(int d)
{
	// TODO
}

/*
* The append function receives an integer,
* and inserts it onto the list, at the back
*/
void LinkedList::append(int d)
{
	// TODO
}

/*
* The prepend funtion receives an integer,
* and inserts it onto the list, at the beginning
*/
void LinkedList::prepend(int d)
{
	// TODO
}

/*
* The remove last function removes the last element from the list 
* and returns its data
*/
int LinkedList::removeLast()
{
	// TODO
	return 0;
}

/*
* The remove first function removes the first element from the list 
* and returns its data
*/
int LinkedList::removeFirst()
{
	//TODO
	return 0;
}

/*
* Returns the size of the linked list
*/
unsigned int LinkedList::getSize()
{
	// TODO
	return 0;
}

/*
* Clears all data from the list
*/
void LinkedList::clear()
{
	//TODO
}
