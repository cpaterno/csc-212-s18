//
// Created by tom on 4/16/18.
//

#include <iostream>
#include "BST.h"

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    clear(root);
}

void BST::clear(Node *node) {
    if (!node) return;

    clear(node->left);
    clear(node->right);
    delete node;
}

Node *BST::insert(int data, Node *node) {
    if (!node) return new Node(data);
    else {
        if (node->data < data) node->right = insert(data, node->right);
        else if (node->data > data) node->left = insert(data, node->left);

        return node;
    }
}

bool BST::search(int data) {
    return search(data, root);
}

bool BST::search(int data, Node *node) {
    if (!node) return false;

    if (node->data == data) return true;
    else if (node->data < data) return search(data, node->right);
    else return search(data, node->left);
}

void BST::remove(int data) {
    root = remove(data, root);
}

Node* BST::min(Node* p) {
    if (p->left) return min(p->left);
    else return p;
}

Node * BST::remove(int data, Node *p) {
    if (!p) return p;

    // Keep searching
    if (data < p->data) p->left = remove(data, p->left);
    else if (data > p->data) p->right = remove(data, p->right);

    // We're on the node we need to delete.
    else {
        // If there's only one child, or no child:
        if (!p->left) {
            Node* temp = p->right;
            delete p;
            return temp;
        } else if (!p->right) {
            Node* temp = p->left;
            delete p;
            return temp;
        } else {
            Node* temp = min(p->right);
            p->data = temp->data;
            p->right = remove(temp->data, p->right);
        }
    }
    return p;
}

void BST::inorder() {
    inorder(root);
    std::cout << std::endl;
}

void BST::inorder(Node *p) {
    if (p) {
        inorder(p->left);
        std::cout << " " << p->data << " ";
        inorder(p->right);
    }
}