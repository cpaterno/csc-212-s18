#include "cdll.h"
#include <iostream>
#include <algorithm>

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

void CDLL::go_first() {
    // TODO
}

void CDLL::go_last() {
    // TODO
}

void CDLL::skip(unsigned int n) {
    // TODO
}

void CDLL::search(const char *word) {
    // TODO
}

void CDLL::print_current() {
    if (current) {
        std::cout << current->time << "    " << current->tweet << std::endl;
    }
}

void CDLL::print_all() {
    if (head) {
        CDLLNode *p = head;
        while (1) {
            std::cout << p->time << " ";
            if (p->next == head) {
                break;
            } else {
                p = p->next;
            }
        }
    }
    std::cout << std::endl;
}
