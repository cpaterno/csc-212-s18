//
// Created by tom on 4/2/18.
//

#ifndef QUICKSORT_DOUBLYLINKEDLIST_H
#define QUICKSORT_DOUBLYLINKEDLIST_H

class DLL_Node {
private:
    DLL_Node *next;
    DLL_Node *previous;
    int data;
public:
    DLL_Node(int d) {
        next = nullptr;
        previous = nullptr;
        data = d;
    }

    ~DLL_Node() {
        next = nullptr;
        previous = nullptr;
    }

    friend class DoublyLinkedList;
};

class DoublyLinkedList {
private:
    DLL_Node *head;
    DLL_Node *tail;
    unsigned int n_elem;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), n_elem(0) {};

    ~DoublyLinkedList();

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
};


#endif //QUICKSORT_DOUBLYLINKEDLIST_H
