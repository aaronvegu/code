#include "Node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {

private:
	Node *first;
public:
	LinkedList();
	void clear();
	void insertFirst(int a);
	void insertLast(int n);
	int extract();
	void toString();
	bool search(int a);
	bool isEmpty();

};

#endif