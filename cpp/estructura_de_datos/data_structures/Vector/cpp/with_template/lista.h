#ifndef LISTA_H
#define LISTA_H
 
#include <iostream>
 
#include "node.cpp"
 
using namespace std;
 
template <class T>
class List {
    public:
        List();
 		
        void newNode(T);
        void buildVector();
        int capacity();
        int size();
        int freeAt();
        bool isFull();
        bool contains(T);
        bool add(T);
        T get(T);
        bool remove(T);
        bool removeAt(T);
        void toString();
        void clear();
    private:
        Node<T> *head;
        Node<T> *tail;
};
 
#endif 