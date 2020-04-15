#include "Node.h"

Node::Node(int n)
{
	load = n;
	next = 0;
}

void Node::setLoad(int n)
{
	load = n;
}

int Node::getLoad()
{
	return load;
}

void Node::setNext(Node* n)
{
	next = n;
}

Node* Node::getNext()
{
	return next;
}