// Stack implementation in c++ with Node has a Class Object
// By: Aaron Vegu

#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()
{
    while(!isEmpty())
        pop();
}

bool Stack::isEmpty()
{
    return (top == NULL);
}

void Stack::push(int l)
{
    Node *newNode = new Node(l);
    newNode->next = top;
    top = newNode;
}

int Stack::pop()
{
    if (!isEmpty())
    {
        Node *temp = top;
        top = temp->next;
        int r = temp->load;
        delete temp;
        return r;
    }
    else return -1;
}

int Stack::peek()
{
    if (!isEmpty())
        return top->load;
    else return -1;
}

string Stack::toString()
{
    string r = "[ ";
    if(isEmpty()) r += "Pila Vacia ";
    else
    {
        Node *current = top;
        while (current != NULL)
        {
            r += to_string(current->load) + " ";
            current = current->next;
        }
    } 
    r += "]";
    return r;
}