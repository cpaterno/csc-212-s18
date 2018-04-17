#include "bst.h"

BSTree::BSTree() {
//
}

BSTree::~BSTree() {
//
}

void BSTree::clear(BSTNode *node) {
//
}

void BSTree::insert(int data) {
//
}

BSTNode *BSTree::rinsert(int data, BSTNode *node) {
//
}

bool BSTree::search(int data) {
//
}

bool BSTree::rsearch(int data, BSTNode *node) {
//
}

void BSTree::remove(int data) {
//
}

BSTNode* BSTree::min(BSTNode* p) {
//
}

BSTNode * BSTree::rremove(int data, BSTNode *p) {
//
}

void BSTree::printPreorder(){
    printPreorder(root);
}
void BSTree::printInorder(){
    printInorder(root);
}
void BSTree::printPostorder(){
    printPostorder(root);
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

