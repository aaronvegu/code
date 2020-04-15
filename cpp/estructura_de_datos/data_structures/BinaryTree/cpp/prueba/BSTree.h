// Binary Search Tree Header File
#ifndef BSTREE_H
#define BSTREE_H

#include "BinaryNode.h"

class BSTree
{
private:
    // Metodos Privados
    BinaryNode* findMin(BinaryNode *t);
    BinaryNode* findMax(BinaryNode *t);
    void makeEmpty(BinaryNode *t);
    void insert(int l, BinaryNode *t);
    void remove(int l, BinaryNode *t);
    bool contains(int l, BinaryNode *t);
    
public:
    // Constructor y Deconstructor
    BSTree(int l);
    ~BSTree();

    // Metodos Publicos
    int findMin();
    int findMax();
    bool isEmpty();
    void makeEmpty();
    void insert(int l);
    void remove(int l);
    bool contains(int l);
};

#endif