#ifndef STACK_H
#define STACK_H

struct Node { // Estructura de Nodo
	int data;
	Node *next;
};

class Stack // Definicion de la clase Stack
{
public:
	Stack(); // Constructor
	~Stack(); // Deconstructor. Es llamado al ejecutar delete <stack>
	bool isEmpty(); // we can know the state of the stack
	void push(int d); // Push a new element into the stack
	int pop(); // Take off the top element of the stack
	int peek(); // Return the load in the top of the stack
	void clear(); // Deletes the entire stack
	std::string toString(); // Displays the stack content
	
private:
	Node *top;
};

#endif