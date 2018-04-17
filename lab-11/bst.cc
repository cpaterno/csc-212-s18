#include "bst.h"
#include <iostream>

BSTree::BSTree() {
//
}

BSTree::~BSTree() {
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

BSTNode* BSTree::min(BSTNode* node) {
//
}

void BSTree::remove(std::string data, BSTNode *node) {
//
}

unsigned int BSTree::treeHeight(BSTNode *node) {
//
}

unsigned int BSTree::treeHeight() {
    return treeHeight(root);
}

void BSTree::printPreorder(){
    printPreorder(root);
    std::cout << std::endl;
}
void BSTree::printInorder(){
    printInorder(root);
    std::cout << std::endl;
}
void BSTree::printPostorder(){
    printPostorder(root);
    std::cout << std::endl;
}

void BSTree::printPostorder(BSTNode* node)
{
     if (node == NULL)
        return;

     printPostorder(node->left);

     printPostorder(node->right);

     std::cout << node->data << " ";
}

void BSTree::printInorder(BSTNode* node)
{
     if (node == NULL)
          return;

     printInorder(node->left);

     std::cout << node->data << " ";

     printInorder(node->right);
}


void BSTree::printPreorder(BSTNode* node)
{
     if (node == NULL)
          return;

     std::cout << node->data << " ";

     printPreorder(node->left);

     printPreorder(node->right);
}
