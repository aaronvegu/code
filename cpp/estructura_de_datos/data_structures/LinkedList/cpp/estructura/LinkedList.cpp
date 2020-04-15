#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// Nodo
struct Node
{
    int load;
    Node* next;
};

// Head
Node* head;

bool Empty()
{
    return head == NULL;
}

int NumItems()
{
    int counter = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}

void InsertFront(int l) 
{
    Node* nodo = new Node();
    nodo->load = l;
    nodo->next = head;
    head = nodo;
}

void InsertRear(int l)
{
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    Node* nodo = new Node();
    temp->next = nodo;
    nodo->load = l;
    nodo->next = NULL;
}

bool InsertInOrder(int l, int index)
{
    if(index >= NumItems()) return false;
    Node* temp = head;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    temp->load = l;
    return true;
}

int RemoveFront()
{
    Node* temp = head;
    head = head->next;
    return temp->load;
}

Node* Find(int n)
{
    if(head->load == n) return head;
    Node* temp = head->next;
    while ((temp->load != n) && (temp != NULL))
    {
        cout << "L. " << temp->load << endl;
        temp = temp->next;
    }
    if(temp->load == n) return temp;
    else return NULL;
}

void ToString()
{
    Node* temp = head;
    cout << "[ ";
    while (temp != NULL)
    {
        cout << temp->load << " ";
        temp = temp->next;
    }
    cout << "]" << endl;
}

int main()
{
    head = NULL;

    InsertFront(3);
    InsertFront(4);
    InsertFront(5);
    InsertFront(6);
    InsertFront(7);
    InsertFront(8);
    InsertRear(2);
    InsertRear(1);
    cout << "Head: " << head->load << endl;
    cout << "Numero de items: " << NumItems() << endl;
    cout << "Lista Enlazada: ";
    ToString();
    InsertInOrder(9, 7);
    cout << "Nueva Lista Enlazada: ";
    ToString();
    cout << "Item al frente: " << RemoveFront() << endl;
    cout << "Nueva Lista Enlazada: ";
    ToString();
    Node* numEncontradoPtr = Find(9);
    cout << "Numero encontrado: " << numEncontradoPtr->load << endl;
    return 0;
}