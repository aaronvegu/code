#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

class Queue
{
private:
	Node *head;
	Node *tail;

public:
	Queue();
	bool isEmpty();
	void enqueue(int);
	int dequeue();
	int peek();
};

#endif