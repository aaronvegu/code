#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue()
{
    head = tail = NULL;
}

Queue::~Queue()
{
    clear();
}

bool Queue::isEmpty()
{
    return head == NULL;
}

void Queue::enqueue(int l)
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

int Queue::dequeue()
{
    if(!isEmpty())
    {
        Node *aux = head;
        head = aux->next;
        int r = aux->load;
        delete aux;
        return r;
    }
    else return -1;
}

int Queue::peek()
{
    if(!isEmpty())
        return head->load;
    else return -1;
}

void Queue::clear()
{
    if(isEmpty()) return;
    Node* current = head;
    while (current != NULL)
    {
        dequeue();
        current = current->next;
    }
    
}

string Queue::toString()
{
    string r = "[ ";
    if (isEmpty())
        r += "Queue Vacia ";
    Node *current = head;
    while (current != NULL)
    {
        r += to_string(current->load) + " ";
        current = current->next;
    }
    r += "]";
    return r;
}

int main()
{

    Queue *cola = new Queue();

    cout << cola->toString() << endl;

    cola->enqueue(1);
    cola->enqueue(2);
    cola->enqueue(3);
    cola->enqueue(4);
    cout << cola->peek() << endl;
    cola->enqueue(5);

    cout << cola->toString() << endl;

    cout << cola->dequeue() << endl;
    cout << cola->dequeue() << endl;

    cout << cola->toString() << endl;

    return 0;
}