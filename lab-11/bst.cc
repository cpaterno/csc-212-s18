#include "bst.h"
#include <iostream>

BSTree::BSTree() {
//
}

BSTree::~BSTree() {
//
}

void BSTree::clear() {
//
}

void BSTree::clear(BSTNode *node) {
//
}

void BSTree::insert(std::string data) {
//
}

void BSTree::insert(std::string data, BSTNode *node) {
//
}

bool BSTree::search(std::string data) {
//
}

bool BSTree::search(std::string data, BSTNode *node) {
//
}

void BSTree::remove(std::string data) {
//
}

void BSTree::remove(std::string data, BSTNode *node) {
//
}

unsigned int BSTree::treeHeight(BSTNode *node) {
//
}

unsigned int BSTree::treeHeight() {
//
}

void BSTree::genPreorderArray(std::string* arr) {
    int idx = 0;
    genPreorderArray(root, arr, &idx);
}

void BSTree::genPreorderArray(BSTNode* node, std::string* arr, int* idx) {
    if (!node) {
        return;
    }
    arr[*idx] = node->data;
    (*idx)++;
    genPreorderArray(node->left, arr, idx);
    genPreorderArray(node->right, arr, idx);
}

void BSTree::genInorderArray(std::string* arr) {
    int idx = 0;
    genInorderArray(root, arr, &idx);
}

void BSTree::genInorderArray(BSTNode* node, std::string* arr, int* idx) {
    if (!node) {
        return;
    }
    genInorderArray(node->left, arr, idx);
    arr[*idx] = node->data;
    (*idx)++;
    genInorderArray(node->right, arr, idx);
}
