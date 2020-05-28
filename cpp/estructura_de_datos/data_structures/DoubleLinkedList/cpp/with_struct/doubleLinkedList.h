#ifndef LIST_H
#define LIST_H

#include "node.cpp"
 
class DoubleLinkedList {
    public:
        DoubleLinkedList();
        bool contains(int);
        bool isEmpty();
        void insertLast(int);
        void insertFirst(int);
        void insertBefore(int,int);
        void insertAfter(int,int);
        void deleteValueByKey(int);
        void insertAt(int,int);
        void updateValueByKey(int,int);
        bool search(int);
        void extract();
        void toString();
        void clear();
    private:
        Node *head;
};
 
#endif 
