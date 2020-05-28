#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{

    Queue<char> cola;

    cola.enqueue('P');
    cola.enqueue('X');
    cola.enqueue('E');
    cola.enqueue('K');
    cola.enqueue('E');

    cout << cola.dequeue() << endl;
    cout << cola.peek() << endl;
    cout << cola.dequeue() << endl;

    cola.enqueue('K');

    cola.toString();

    return 0;
}