#ifndef NODE_H
#define NODE_H

class Node 
{
private:
    int load;
    Node* next;

public:
    Node(int l);
    int GetLoad();
    void SetLoad(int load);
    Node* GetNext();
    void SetNext(Node* next);
};

#endif