#pragma once
#include "NodeInterface.h"

class Node: public NodeInterface
{
private:
    int item;
    Node* left;
    Node* right;
    
public:
    friend class BST;
    
    Node(int itemIn)
    {
        item = itemIn;
        left = NULL;
        right = NULL;
    }
    virtual ~Node(){}

    int getData() const
    {
        return item;
    }

    NodeInterface * getLeftChild() const
    {
        return left;
    }

    NodeInterface * getRightChild() const
    {
        return right;
    }

};
