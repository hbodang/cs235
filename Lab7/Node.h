#pragma once
#include "NodeInterface.h"
#include <algorithm>

using namespace std;

class Node: public NodeInterface
{
private:
    int item;
    Node* left;
    Node* right;
	
public:
    friend class AVL;
    
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
    
    virtual int getHeight()
    {
		int lefty = 0;
		int righty = 0;

		if(this->right == NULL && this->left == NULL)
		{
			return 1;
		}
		else if (this->right == NULL)
		{
			return this->left->getHeight() +1;
		}
		else if (this->left == NULL)
		{
			return this->right->getHeight() +1;
		}
		else
		{
			lefty = this->left->getHeight() +1;
			righty = this->right->getHeight() +1;
			return max(lefty, righty);
		}
	}
    
};
