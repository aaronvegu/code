#include <iostream>
#include "BinaryTree.h"

BinaryTree::BinaryTree(int data)
{   // Inicializamos el arbol
    TreeNode *node = new TreeNode(); // Creamos un nuevo nodo
    node->data = data; // Almacenamos la carga
    node->left = node->right = NULL; // y sus apuntadores a hijos izq y der a NULL
    setRoot(node); // Seeteamos el root a la direccion del nuevo nodo
}

void BinaryTree::setRoot(TreeNode* node)
{
    root = node;
}

TreeNode* BinaryTree::getRoot()
{
    return root;
}