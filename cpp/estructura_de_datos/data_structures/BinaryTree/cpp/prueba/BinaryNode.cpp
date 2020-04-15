#include "BinaryNode.h"

BinaryNode::BinaryNode(int l)
{
    load = l;
    left = nullptr;
    right = nullptr;
}

BinaryNode::~BinaryNode()
{
}

void BinaryNode::setLoad(int l)
{
    load = l;
}

int BinaryNode::getLoad()
{
    return load;
}

void BinaryNode::setLeft(BinaryNode *p)
{
    left = p;
}

BinaryNode* BinaryNode::getLeft()
{
    return left;
}

void BinaryNode::setRight(BinaryNode *p)
{
    right = p;
}

BinaryNode* BinaryNode::getRight()
{
    return right;
}