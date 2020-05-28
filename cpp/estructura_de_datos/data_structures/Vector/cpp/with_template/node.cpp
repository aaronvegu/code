#include "node.h"
 
template<typename T>
Node<T>::Node() {
    value = NULL;
    next = NULL;
}
 
template<typename T>
Node<T>::Node(T value) {
    value = value;
    next = NULL;
}

template<typename T>
Node<T>* Node<T>::getNext(){
	return next;
}

template<typename T>
void Node<T>::setNext(Node* node){
	next = node;
}

template<typename T>
T Node<T>::getValue(){
	return value;
}

template<typename T>
void Node<T>::setValue(T v){
	value = v;
}
