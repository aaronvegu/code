#ifndef BINARYNODE_H
#define BINARYNODE_H

class BinaryNode
{
private:
    int load;
    BinaryNode *left;
    BinaryNode *right;
public:
    BinaryNode(int l);
    ~BinaryNode();

    // Setter & Getters
    void setLoad(int l);
    int getLoad();
    void setLeft(BinaryNode *p);
    BinaryNode* getLeft();
    void setRight(BinaryNode *p);
    BinaryNode* getRight();
};

#endif