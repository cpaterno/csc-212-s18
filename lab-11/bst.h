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
        bool search(std::string data, BSTNode* node);
        void insert(std::string data, BSTNode* node);
        void remove(std::string data, BSTNode* node);
        //void destroy(BSTNode* node);
        unsigned int treeHeight(BSTNode* node);
	void printPreorder(BSTNode* node);
	void printInorder(BSTNode* node);
	void printPostorder(BSTNode* node);

    public:
        BSTree();
        ~BSTree();

		/* Public Methods */
        void insert(std::string data);
        void remove(std::string data);
        bool search(std::string data);
        unsigned int treeHeight();
        void clear(BSTNode* node);
        BSTNode* min(BSTNode* node);
	    //Traversals
    	void printPreorder();
    	void printInorder();
    	void printPostorder();

};

#endif
