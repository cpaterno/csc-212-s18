//
// Created by tom on 4/1/18.
//

#include <stdexcept>
#include "linkedlist.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>

/*
*  Node Constructor
*/
Node::Node(int d) {
    data = d;
    next = nullptr;
}

/*
* Node Destructor
*/
Node::~Node() {
    // No dynamic memory, nothing to deconstruct
}

/*
* List Constructor
*/
LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    n_elem = 0;
}

/*
* List Destructor
*/
LinkedList::~LinkedList() {
    Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
    n_elem = 0;
    head = nullptr;
    tail = nullptr;
}

/*
* The insertAt function receives an index, and a value
* and inserts it at that index in the list
*/
void LinkedList::insertAt(unsigned int index, int d) {
    if (index > n_elem) throw "Bad Index";

    // Base Cases (are we really prepending or appending?
    if (!index) return prepend(d);
    if (index == n_elem) return append(d);

    // Otherwise:
    Node *new_node = new Node(d);
    Node *temp = head;
    for (int i = 0; i < index; ++i) temp = temp->next;
    new_node->next = temp->next;
    temp->next = new_node;
    ++n_elem;
}

/*
* The removeAt function receives an index,
* and removes the element at that index
*/
int LinkedList::removeAt(unsigned int index) {
    // Validity
    if (index < 0 || n_elem < index) throw "Index out of bounds";

    // Base cases.
    if (!index) removeFirst();
    if (index == n_elem) removeLast();

    // Otherwise.
    Node* temp = head;
    for (int i=0; i<index; ++i) temp = temp->next;
    Node* remove = temp->next;
    int ret = remove->data;
    temp->next = remove->next;
    delete remove;
    return ret;
}

/*
* The find function receives an integer,
* and returns if it is in the list
*/
bool LinkedList::find(int d) {
    Node *temp = head;
    while (temp) {
        if (temp->data == d) return true;
        temp = temp->next;
    }
    return false;
}

/*
* The append function receives an integer,
* and inserts it onto the list, at the back
*/
void LinkedList::append(int d) {
    Node *new_node = new Node(d);
    if (!n_elem) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    ++n_elem;
}

/*
* The prepend function receives an integer,
* and inserts it onto the list, at the beginning
*/
void LinkedList::prepend(int d) {
    Node *new_node = new Node(d);
    new_node->next = head;
    head = new_node;
    if (!n_elem) tail = new_node;
    ++n_elem;
}

/*
* The remove last function removes the last element from the list
* and returns its data
*/
int LinkedList::removeLast() {
    if (!n_elem) throw "Nothing to remove";

    // Save last element.
    int ret = tail->data;

    // Delete last node.
    if (n_elem == 1) {
        delete tail;
        head = nullptr;
        tail = nullptr;
        --n_elem;
        return ret;
    }
    Node* temp = head;
    while (temp->next != tail) temp=temp->next;
    delete temp->next;
    temp->next = nullptr;
    tail = temp;
    --n_elem;
    return ret;
}

/*
* The remove first function removes the first element from the list
* and returns its data
*/
int LinkedList::removeFirst() {
    if (n_elem) {
        Node* temp = head->next;
        int ret = head->data;
        delete head;
        head = temp;
        --n_elem;
        return ret;
    }
}

/*
* Returns the size of the linked list
*/
unsigned int LinkedList::getSize() {
    return n_elem;
}

/*
* Clears all data from the list
*/
void LinkedList::clear() {
    Node* temp;
    while (head) {
        temp = head->next;
        delete head;
        head = temp;
    }
    head = nullptr;
    tail = nullptr;
    n_elem = 0;
}

/*
* Prints the contents of the linked list in index:data format,
* along with the head and tail with their respective data
*
* Note: if the pointers from one node to another are not properly
* handled this method may fail or have unexpected results.
*/
void LinkedList::print() {
    Node *n = head;
    int i = 0;
    while (n != NULL) {
        std::cout << i++ << ':' << n->data << std::endl;
        n = n->next;
    }
    if (head != NULL) std::cout << "Head:" << head->data << std::endl;
    if (tail != NULL) std::cout << "Tail:" << tail->data << std::endl;
}

void LinkedList::reverse() {
    if (!head) return;
    Node *p = nullptr;
    Node *c = head;
    Node *n = c->next;
    while (n) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    std::swap(head, tail);
}
