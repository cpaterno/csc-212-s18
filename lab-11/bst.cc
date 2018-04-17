//
// Created by tom on 4/16/18.
//

#include "BST.h"

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

void BSTree::printPostorder(BSTNode* node)
{
     if (node == NULL)
        return;

     printPostorder(node->left);

     printPostorder(node->right);

     printf("%d ", node->data);
}
 
void BSTree::printInorder(BSTNode* node)
{
     if (node == NULL)
          return;

     printInorder(node->left);
 
     printf("%d ", node->data);  
 
     printInorder(node->right);
}
 

void BSTree::printPreorder(BSTNode* node)
{
     if (node == NULL)
          return;
 
     printf("%s ", node->data);  
 
     printPreorder(node->left);  
 
     printPreorder(node->right);
}    
