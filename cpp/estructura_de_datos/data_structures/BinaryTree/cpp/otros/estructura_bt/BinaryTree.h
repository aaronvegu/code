#ifndef BINARYTREE_H
#define BINARYTREE_H

// Definimos la estructura del Nodo para arbol binario
struct TreeNode {
    int data;
    TreeNode *right;
    TreeNode *left;
};

class BinaryTree // Declaracion de la clase BinaryTree
{
private:
    TreeNode *root;
public:
    BinaryTree(int data);
    //~BinaryTree();
    void setRoot(TreeNode* node);
    TreeNode* getRoot();
};


#endif