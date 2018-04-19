//
// Created by tom on 4/16/18.
//

#ifndef BST_BST_H
#define BST_BST_H

class Node {
private:
    Node* left;
    Node* right;
    int data;
public:
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
    ~Node() {
        left = nullptr;
        right = nullptr;
    };
    friend class BST;
};

class BST {
private:
    // Data
    Node* root;

    // Private API calls (tags on extra parameter)
    Node* insert(int, Node *p);
    bool search(int, Node *p);
    Node * remove(int, Node *p);
    void clear(Node*);

    Node* min(Node*);
    void inorder(Node*);
public:
    BST();
    ~BST();
    void clear() {
        clear(root);
        root = nullptr;
    }
    void insert(int data) { root = insert(data, root); }
    bool search(int);
    void remove(int);
    void inorder();
};


#endif //BST_BST_H
