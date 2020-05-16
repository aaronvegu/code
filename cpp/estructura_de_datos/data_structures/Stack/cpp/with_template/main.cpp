#include "Stack.h"

using namespace std;

int main()
{

    Stack<char> pila;

    pila.toString();

    pila.push('P');
    pila.push('X');
    pila.push('E');
    pila.push('K');
    pila.push('E');

    cout << pila.pop() << endl;
    cout << pila.peek() << endl;
    cout << pila.pop() << endl;

    pila.push('K');

    pila.toString();

    return 0;
}