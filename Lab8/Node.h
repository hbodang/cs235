#pragma once
#include "NodeInterface.h"
#include <algorithm>

using namespace std;

class Node: public NodeInterface
{
private:
    int frequency;
    char value;

	
public:
    Node* left;
    Node* right;
    
    Node(char theValue, int theFrequency)
    {
        value = theValue;
        frequency = theFrequency;
        left = NULL;
        right = NULL;
    }
    virtual ~Node(){}
    
    
    char getCharacter() const
    {
        return value;
    }
    
    int getFrequency() const
    {
        return frequency;
    }
    
    NodeInterface * getLeftChild() const
    {
        return left;
    }
    
    NodeInterface * getRightChild() const
    {
        return right;
    }
    
    /*void setFrequency(int i)
    {
        frequency = i;
    }
    
    void setValue(char v)
    {
        value = v;
    }*/
};
