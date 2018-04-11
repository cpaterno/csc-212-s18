//
// Created by tom on 4/9/18.
//

#include "stack.h"

Stack::Stack(unsigned int c) {
    data = new int[c];
    top = 0;
    capacity = c;
}

Stack::~Stack() {
    delete[] data;
    capacity = 0;
    top = 0;
}

void Stack::push(int val) {
    if (top == capacity) throw "No more room";
    data[top++] = val;
}

int Stack::pop() {
    if (!top) throw "No elements to give";
    return data[--top];
}

int Stack::peek() {
    return data[top - 1];
}

