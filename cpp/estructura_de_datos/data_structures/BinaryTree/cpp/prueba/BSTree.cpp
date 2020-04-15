#include <iostream>
#include "BSTree.h"

using namespace std;

BinaryNode *root;

BSTree::BSTree(int l)
{
    BinaryNode *nodo = new BinaryNode(l);
    root = nodo;
    delete nodo;
}

BSTree::~BSTree()
{

}

int BSTree::findMin()
{
    return 0;
}

int BSTree::findMax()
{
    return 0;
}

bool BSTree::isEmpty()
{
    return false;
}

void BSTree::makeEmpty()
{

}

void BSTree::insert(int l)
{
    
}

void BSTree::remove(int l)
{

}

bool BSTree::contains(int l)
{
    return false;
}

int main()
{
    return 0;
}