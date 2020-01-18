//
//  BST.h
//  Lab6
//
//  Created by Haley Dennis on 5/15/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#pragma once
#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface
{
public:
    BST() {root = NULL;}
    virtual ~BST() {clear();}
    
    NodeInterface * getRootNode() const;

    bool add(int data); //recursively calls insert
    
    bool insert(Node*&, int data);
    
    bool remove(int item); //recursively calls remove

    bool erase(Node*&, int data);

    void clear();
    
    bool find(int item); //recursively calls search
    
    bool search(Node*& local_root, int target);
    
private:
    Node* root;
};
