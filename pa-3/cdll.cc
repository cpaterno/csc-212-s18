#include "cdll.h"
#include <iostream>

CDLLNode::CDLLNode(const char *ti, const char *tw) {
    time = ti;
    tweet = tw;
    next = NULL;
    prev = NULL;
}

CDLLNode::~CDLLNode() {
    // no dynamic memory allocation, nothing to destroy
}

CDLL::CDLL() {
    // TODO: Initialize private data members
}

CDLL::~CDLL() {
    // TODO: Needs to delete ALL elements from the list
}

void CDLL::prepend(const char *time, const char *tweet) {
    // TODO: Inserts a node at front
}

void CDLL::append(const char * time, const char * tweet) {
    // TODO: Inserts a node at end
}

void CDLL::go_next() {
    // TODO
}

void CDLL::go_prev() {
    // TODO
}

void CDLL::go_last() {
    // TODO
}

void CDLL::skip(unsigned int n) {
    // TODO
}

void CDLL::print_current() {
    if (current) {
        std::cout << current->time << "    " << current->tweet << std::endl;
    }
}
