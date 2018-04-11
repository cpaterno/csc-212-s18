//
// Created by tom on 4/1/18.
//

#ifndef QUICKSORT_LINKEDLIST_H
#define QUICKSORT_LINKEDLIST_H


#ifndef NULL
#define NULL 0x00
#endif

class Node {

private:
    Node *next;
    int data;

public:
    Node(int d);

    ~Node();

    friend class LinkedList;

};

class LinkedList {

private:
    Node *head;
    Node *tail;
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

    void reverse();

    int first();

    int last();
};

#endif //QUICKSORT_LINKEDLIST_H
