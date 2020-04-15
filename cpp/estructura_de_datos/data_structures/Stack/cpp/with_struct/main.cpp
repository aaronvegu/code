#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

	Stack *s = new Stack();
	cout << s->toString() << endl;
	s->push(1);
	s->push(2);
	s->push(3);
	cout << s->pop() << endl;
	cout << s->toString() << endl;
	cout << s->pop() << endl;
	cout << s->toString() << endl;
	s->push(8);
	s->push(5);
	cout << s->toString() << endl;
	s->clear();
	/*
	delete s; // Delete trabaja con apuntadores, y nuestro Stack s
			  // es un apuntador. Al parecer al realizar delete a 
			  // nuestro Stack s, se llama a su deconstructor 
	*/

	return 0;
}