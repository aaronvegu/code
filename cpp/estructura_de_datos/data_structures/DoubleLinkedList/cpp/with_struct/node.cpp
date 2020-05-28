#include "node.h"
 
Node::Node() {
    data = 0;
    next = NULL;
    previous = NULL;
}

Node::Node(int v) {
    data = v;
    next = NULL;
    previous = NULL;
}

int Node::getData(){
	return data;
}

void Node::setData(int v) {
    data = v;
}

Node* Node::getNext(){
	return next;
}

void Node::setNext(Node* node){
	next = node;
}

Node* Node::getPrevious(){
	return previous;
}

void Node::setPrevious(Node* node){
	previous = node;
}
