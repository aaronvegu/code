#include <iostream>
#include "Node.h"

Node::Node(int n)
{
    load = n;
    next = NULL;
}

void Node::SetLoad(int n)
{
    load = n;
}

int Node::GetLoad()
{
    return load;
}

void Node::SetNext(Node* n)
{
    next = n;
}

Node* Node::GetNext()
{
    return next;
}