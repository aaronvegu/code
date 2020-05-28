#include "node.h"
 
Node::Node() {
    value = 0;
    next = NULL;
}

Node::Node(int v) {
    value = v;
    next = NULL;
}

int Node::getValue(){
	return value;
}

void Node::setValue(int v) {
    value = v;
}

Node* Node::getNext(){
	return next;
}

void Node::setNext(Node* node){
	next = node;
}
