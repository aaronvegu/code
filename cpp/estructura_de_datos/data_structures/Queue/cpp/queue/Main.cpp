#include <iostream>
#include "Node.h"
#include "Queue.h"

using namespace std;

int main()
{
	Queue cola;
	cout << cola.peek() << endl;
	cout << cola.dequeue() << endl;
	cola.enqueue(3);
	cola.enqueue(4);
	cola.enqueue(5);
	cout << cola.dequeue() << endl;
	cout << cola.peek() << endl;
	//cout << cola.peek() << endl;
	return 0;
}
