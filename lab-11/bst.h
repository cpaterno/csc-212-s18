#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <string>

#ifndef NULL
#define NULL 0x00
#endif

#ifndef MAX
#define MAX(a,b) ((a > b) ? a : b)
#endif

class BSTNode
{
    private:
        std::string data;
		int count;
        BSTNode *left;
        BSTNode *right;

    public:
        BSTNode(std::string d) { data = d; left = right = NULL; }
        ~BSTNode() { }

    friend class BSTree;
};

class BSTree
{
    private:
        BSTNode *root;

		/* Helper Methods */
        bool search(BSTNode *p, std::string d);
        void insert(BSTNode *p, std::string d);
        void destroy(BSTNode *p);
        int BST_Height(BSTNode*);

    public:
        BSTree();
        ~BSTree();

		/* Public Methods */
        void insert(std::string d);
        bool search(std::string d);
        int BST_Height();
};

#endif
