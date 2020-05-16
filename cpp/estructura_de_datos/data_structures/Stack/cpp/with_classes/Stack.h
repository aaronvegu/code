#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <iostream>

class Stack
{
private:
    Node *top; // Apuntador al top del stack
public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(int load);
    int pop();
    int peek();
    std::string toString();
};

#endif