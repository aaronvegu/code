#include "node.h"
 
template<typename T>
Node<T>::Node() {
    data = NULL;
    next = NULL;
    previous = NULL;
}
 
template<typename T>
Node<T>::Node(T data) {
    data = data;
    next = NULL;
    previous = NULL;
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
Node<T>* Node<T>::getPrevious(){
	return previous;
}

template<typename T>
void Node<T>::setPrevious(Node* node){
	previous = node;
}

template<typename T>
T Node<T>::getData(){
	return data;
}

template<typename T>
void Node<T>::setData(T v){
	data = v;
}
