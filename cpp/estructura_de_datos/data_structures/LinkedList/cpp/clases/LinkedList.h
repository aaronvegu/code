#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
private:
    Node* head;

public:
    LinkedList(Node* h);
    Node* GetHead();
    void SetHead(Node* head);
    bool Empty();
    int NumItems();
    void InsertFront(int load);
    void InsertRear(int load);
    void InsertInOrder(int load, int index);
    int RemoveFront();
    Node* Find(int load);
    void ToString();
};



#endif