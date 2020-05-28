#include "Queue.h"
#include <iostream>

Queue::Queue()
{
	head = tail = 0;
}

bool Queue::isEmpty()
{
	if(head == 0) return true;
	else return false;
}

void Queue::enqueue(int n)
{
	Node nuevoNodo(n);
	if(isEmpty()) {
		head = &nuevoNodo;
		tail = &nuevoNodo;
	} else {
		tail->setNext(&nuevoNodo);
		tail = &nuevoNodo;
	}
}

int Queue::dequeue()
{
	if (isEmpty() == true) return -1;
	else {
		int aux = head->getLoad();
		Node *a = head;
		head = a->getNext();
		return aux;
	}
}

int Queue::peek()
{
	if(isEmpty() == true) return -1;
	else return head->getLoad();
}
