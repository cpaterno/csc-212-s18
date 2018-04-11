//
// Created by tom on 4/9/18.
//

#ifndef WPS_09_SOLUTIONS_STACK_H
#define WPS_09_SOLUTIONS_STACK_H


class Stack {
private:
    int *data;
    int capacity;
    int top;
public:
    Stack(unsigned int c = 100);

    ~Stack();

    void push(int);

    int pop();

    int peek();
};


#endif //WPS_09_SOLUTIONS_STACK_H
