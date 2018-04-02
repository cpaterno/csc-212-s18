//
// Created by tom on 4/2/18.
//

#include <lzma.h>
#include "DoublyLinkedList.h"

DoublyLinkedList::~DoublyLinkedList() {
    DLL_Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
    n_elem = 0;
    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::insertAt(unsigned int index, int d) {
    if (index < 0 || n_elem < index) throw "Invalid index";

    if (!index) return prepend(d);
    if (index == n_elem) return append(d);

    auto node = new DLL_Node(d);
    DLL_Node* temp = head;
    for (int i=0; i<index; ++i) temp = temp->next;
    node->next = temp->next;
    node->previous = temp;
    temp->next = node;
    node->next->previous = node;

    ++n_elem;
}

int DoublyLinkedList::removeAt(unsigned int index) {
    if (index < 0 || n_elem < index) throw "Invalid index";

    if (!index) return removeFirst();
    if (index == n_elem) return removeLast();

    DLL_Node* temp = head;
    for (int i=0; i<index; ++i) temp = temp->next;
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    int ret = temp->data;
    delete temp;
    --n_elem;
    return ret;
}

bool DoublyLinkedList::find(int d) {
    return false;
}

void DoublyLinkedList::append(int d) {
    auto new_node = new DLL_Node(d);
    if (!n_elem) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        new_node->previous = tail;
        tail = new_node;
    }
    ++n_elem;
}

void DoublyLinkedList::prepend(int d) {
    auto new_node = new DLL_Node(d);
    if (!n_elem) {
        head = new_node;
        tail = new_node;
    } else {
        head->previous = new_node;
        new_node->next = head;
        head = new_node;
    }
    ++n_elem;
}

int DoublyLinkedList::removeLast() {
    if (!n_elem) throw "Nothing to remove";
    int ret = tail->data;
    DLL_Node* remove = tail;
    if (n_elem == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail->previous->next = nullptr;
        tail = tail->previous;
    }
    delete remove;
    --n_elem;
    return ret;
}

int DoublyLinkedList::removeFirst() {
    if (!n_elem) throw "Nothing to remove";
    int ret = head->data;
    DLL_Node* remove = head;
    if (n_elem == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->previous = nullptr;
    }
    delete remove;
    --n_elem;
    return ret;
}

unsigned int DoublyLinkedList::getSize() {
    return n_elem;
}

void DoublyLinkedList::clear() {

}

void DoublyLinkedList::print() {

}

void DoublyLinkedList::reverse() {

}
