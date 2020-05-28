#include <iostream>

#ifndef NODE_H
#define NODE_H
 
template <class T>
class Node {
    public:
        Node();
        Node(T);
        
        Node* getNext();
        Node* getPrevious();
        T getData();
        void setNext(Node*);
        void setPrevious(Node*);
        void setData(T);
	private:
        Node *next;
        Node *previous;
        T data;
};
 
#endif 
