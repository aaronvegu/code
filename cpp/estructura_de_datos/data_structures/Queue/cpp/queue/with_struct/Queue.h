#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue
{
private:
    struct Node
    {
        int load;
        Node *next;
    };
    Node *head;
    Node *tail;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enqueue(int load);
    int dequeue();
    int peek();
    void clear();
    std::string toString();
};

#endif