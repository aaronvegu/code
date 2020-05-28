#include <iostream>
 
using namespace std;

#ifndef NODE_H
#define NODE_H
 
template <class T>
class Node {
    public:
        Node();
        Node(T);
 		
 		Node* getNext();
        T getValue();
        void setNext(Node*);
        void setValue(T);
    private:
        Node *next;
        T value;
};
 
#endif 
