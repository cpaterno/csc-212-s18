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
        bool search(BSTNode*, std::string);
        void insert(BSTNode*, std::string);
        void remove(BSTNode*, std::string);
        void destroy(BSTNode*);
        unsigned int treeHeight(BSTNode*);
	void printPreorder(BSTNode* node);
	void printInorder(BSTNode* node);
	void printPostorder(BSTNode* node);

    public:
        BSTree();
        ~BSTree();

		/* Public Methods */
        void insert(std::string);
        void remove(std::string);
        bool search(std::string);
        unsigned int treeHeight();
	//Traversals
	void printPreorder();
	void printInorder();
	void printPostorder();
};

#endif
