#ifndef NODE_H
#define NODE_H

class Node
{
private:
	int load;
	Node *next;

public:
	Node(int n);
	int getLoad();
	void setLoad(int n);
	Node* getNext();
	void setNext(Node* n);
};

#endif
