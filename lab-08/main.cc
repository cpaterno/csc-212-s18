#include <iostream>
#include "darray.h"

void print(DArray* darr) {
    for (int i = 0; i < darr->size(); i++) {
        std::cout << darr->at(i) << ' ';
    } std::cout << std::endl;
}

int main() {

    /* Correctness Testing for DArray Goes Here */

    return 0;
}
