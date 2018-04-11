//
// Created by tom on 4/9/18.
//

#ifndef WPS_09_SOLUTIONS_QUEUE_H
#define WPS_09_SOLUTIONS_QUEUE_H

#include "../lists/linkedlist.h"

class Queue : public LinkedList {
public:
    void push(int val);

    int pop();

    int peek();
};


#endif //WPS_09_SOLUTIONS_QUEUE_H
