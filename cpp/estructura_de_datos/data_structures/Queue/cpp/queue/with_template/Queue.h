#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    struct Node
    {
        T load;
        Node *next;
    };
    Node *head;
    Node *tail;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enqueue(T load);
    T dequeue();
    T peek();
    void clear();
    void toString();
};

template <class T>
Queue<T>::Queue()
{
}

template <class T>
Queue<T>::~Queue()
{
    clear();
}

template <class T>
bool Queue<T>::isEmpty()
{
    return head == NULL;
}

template <class T>
void Queue<T>::enqueue(T l)
{
    Node *newNode = new Node();
    newNode->load = l;
    if(isEmpty())
    {
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

template <class T>
T Queue<T>::dequeue()
{
    if(!isEmpty())
    {
        Node *aux = head;
        head = aux->next;
        T r = aux->load;
        delete aux;
        return r;
    }
    else return -1;
}

template <class T>
T Queue<T>::peek()
{
    if(!isEmpty())
        return head->load;
    else return -1;
}

template <class T>
void Queue<T>::clear()
{
    if(isEmpty()) return;
    Node* current = head;
    while (current != NULL)
    {
        dequeue();
        current = current->next;
    }
    
}

template <class T>
void Queue<T>::toString()
{
    cout << "[ ";
    if (isEmpty())
        cout << "Queue Vacia " << endl;
    else
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->load << " ";
            current = current->next;
        }
    }
    cout << "]" << endl;
}

#endif