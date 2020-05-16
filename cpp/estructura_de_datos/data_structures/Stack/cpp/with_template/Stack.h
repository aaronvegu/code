#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    struct Node // Nodo como struct
    {
        T load;
        Node *next;
    };
    Node *top; // Apuntador al inicio de la Pila

public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(T load);
    T pop();
    T peek();
    void toString();
};

// Constructor
template <class T>
Stack<T>::Stack()
{
    top = NULL;
}

// Destructor
template <class T>
Stack<T>::~Stack()
{

}

// Check if the Stack is empty
template <class T>
bool Stack<T>::isEmpty()
{
    return top == NULL;
}

// Push Method
template <class T>
void Stack<T>::push(T l)
{
    Node *newNode = new Node();
    newNode->load = l;
    newNode->next = top;
    top = newNode;
}

// Pop method
template <class T>
T Stack<T>::pop()
{
    if(!isEmpty())
    {
        Node *temp = top;
        top = temp->next;
        int r =  temp->load;
        delete temp;
        return r;
    }
    else return -1;
}

// Peek Method
template <class T>
T Stack<T>::peek()
{
    if(isEmpty()) return -1;
    else return top->load;
}

// Turn the content of the stack to string
template <class T>
void Stack<T>::toString()
{
    cout << "[ ";
    if (isEmpty()) cout << "Pila Vacia ";
    else
    {
        Node *current = top;
        while (current != NULL)
        {
            cout << current->load << " ";
            current = current->next;
        }
    }    
    cout << "]" << endl;
}

#endif