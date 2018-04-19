#include <iostream>
#include <cassert>
#include "BST.h"

void test_clear();

void test_remove();

void test_search() {
    // Setup
    BST tree = BST();
    for (int i=0; i<10; ++i)
        tree.insert(i);

    // Print contents for visual inspection
    tree.inorder();

    // Tests:
    assert(tree.search(5));
    assert(tree.search(9));
    assert(tree.search(0));
    assert(!tree.search(10));
    assert(!tree.search(-1));
    std::cout << "Search passed" << std::endl;
}

void test_insert() {
    for (int i=0; i<5; ++i) {
        BST tree = BST();
        for (int i=0; i<10; ++i)
            tree.insert(std::rand() % 100);
        tree.inorder();
    }
    std::cout << "Insert passed!" << std::endl;
}

int main() {
    test_insert();
    test_search();
    test_clear();
    test_remove();
}

void test_remove() {
    BST tree = BST();
    tree.insert(10);
    tree.insert(5);
    tree.insert(12);
    tree.insert(8);
    tree.insert(19);
    tree.insert(6);
    tree.insert(2);
    tree.insert(11);
    tree.insert(15);
    tree.insert(9);
    tree.insert(7);

    tree.remove(7);
    tree.remove(12);
    tree.remove(8);
    tree.remove(10);

    tree.inorder();
}

void test_clear() {
    std::cout << "Testing clear" << std::endl;
    BST tree = BST();
    for (int i=0; i<10; ++i) {
        tree.clear();
        for (int j=0; j<10; ++j) tree.insert(i*10+j);
        tree.inorder();
    }
    std::cout << "Clear passed" << std::endl;
}