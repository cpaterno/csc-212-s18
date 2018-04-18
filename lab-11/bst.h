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
        BSTNode(std::string d) { data = d; count = 1; left = right = NULL; }
        ~BSTNode() { }

    friend class BSTree;
};

class BSTree
{
    private:
        BSTNode *root;

        /* Helper Methods */
        int search(std::string data, BSTNode* node);
        void insert(std::string data, BSTNode* node);
        BSTNode* remove(std::string data, BSTNode* node);
        void clear(BSTNode* node);
        int treeHeight(BSTNode* node);
        /* Test Methods */
    	void genPreorderArray(BSTNode* node, std::string* arr, int* idx);
    	void genInorderArray(BSTNode* node, std::string* arr, int* idx);

    public:
        BSTree();
        ~BSTree();

        /* Public Methods */
        void insert(std::string data);
        void remove(std::string data);
        int search(std::string data);
        int treeHeight();
        void clear();
        /* Test Methods */
    	void genPreorderArray(std::string* arr);
    	void genInorderArray(std::string* arr);

};

#endif
