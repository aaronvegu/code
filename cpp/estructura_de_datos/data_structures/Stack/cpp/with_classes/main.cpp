#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{

    Stack pila;

    cout << pila.toString() << endl;

    pila.push(5);
    pila.push(4);
    pila.push(3);
    pila.push(2);
    pila.push(1);

    cout << pila.pop() << endl;
    cout << pila.peek() << endl;

    cout << pila.toString() << endl;

    return 0;
}