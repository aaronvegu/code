#ifndef NODE_H
#define NODE_H
 
class Node {
    public:
        Node();
        Node(int);
        int getData();
        void setData(int);
        Node* getNext();
        void setNext(Node*);
        Node* getPrevious();
        void setPrevious(Node*);
 	private:
 		int data;
        Node *next;
        Node *previous;
};
 
#endif 
