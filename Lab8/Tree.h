//
//  Tree.h
//  Lab8
//
//  Created by Haley Dennis on 5/25/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#pragma once

#include "TreeInterface.h"

using namespace std;

class Tree
{
private:

public:
    Node* root;
    
    Tree() {root = NULL;}
    virtual ~Tree() {}
    
    NodeInterface * getRootNode() const
    {
        return root;
    }
    
    bool is_leaf() const
    {
        if (root != NULL)
        {
            return root->left == NULL && root->right == NULL;
        }
        else
            return true;
    }
};
