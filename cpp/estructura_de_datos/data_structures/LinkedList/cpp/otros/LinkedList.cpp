#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(){
	first = nullptr;
}

void LinkedList::clear() {
	while(!isEmpty()) {
		extract();
	}
}

void LinkedList::insertFirst(int a) {
	if (isEmpty()) {
		Node nuevoNodo(a);
		first = &nuevoNodo;
	} else {
		Node nuevoNodo(a);
		nuevoNodo.setNext(first);
		first = &nuevoNodo;
	}
}

void LinkedList::insertLast(int a) {
	if (isEmpty()) {
		Node nuevoNodo(a);
		first = &nuevoNodo;
	} else {
		Node *temporal = first;
		while(temporal->getNext() != nullptr) temporal = temporal->getNext();
		Node nuevoNodo(a);
			temporal->setNext(&nuevoNodo);
	}
}

bool LinkedList::isEmpty() {
	return (first == nullptr);
}

int LinkedList::extract() {
	if (isEmpty()) return -1;
	else {
		Node * temporal = first;
		int r = temporal->getLoad();
		first = first->getNext();
		//delete temporal;
		return r;
	}
}

void LinkedList::toString() {
	std::string contenido = "";
}

bool LinkedList::search(int a) {
	Node *temporal = first;
	while(temporal->getNext() != nullptr) {
		if (temporal->getLoad() == a) return true;
		else temporal = temporal->getNext();
	}
	return false;
}

