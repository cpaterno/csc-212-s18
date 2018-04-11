//
// Created by tom on 4/9/18.
//

#include "queue.h"

void Queue::push(int val) {
    append(val);
}

int Queue::pop() {
    return removeFirst();
}

int Queue::peek() {
    return first();
}