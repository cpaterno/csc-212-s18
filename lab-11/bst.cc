#include "bst.h"

#include <iostream>
#include <string>

BSTree::BSTree()
{
    root = NULL;
}

BSTree::~BSTree()
{
    destroy(root);
}

void BSTree::destroy(BSTNode *p)
{
    if (p)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

bool BSTree::search(BSTNode* p, std::string d)
{
    if (p)
    {
        if(p->data == d) {
			return true;
		} else if(p->data > d) {
			return search(p->left, d);
		} else {
			return search(p->right, d);
		}
    }
    return false;
}

/*
*  Functions you will be implementing
*/

void BSTree::insert(BSTNode *p, std::string d)
{
        //TODO
}


int BSTree::BST_Height(BSTNode *p)
{
        //TODO

    return -1;

}

/*
*   Helper Functions: These are the public methods
*/

bool BSTree::search(std::string d)
{
    return search(root, d);
}

void BSTree::insert(std::string d)
{
    insert(root, d);
}

int BSTree::BST_Height()
{
    if(root)
        return BST_Height(root);
    else
        return 0;
}
