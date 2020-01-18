//
//  AVL.h
//  Lab6
//
//  Created by Haley Dennis on 5/15/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#pragma once
#include "AVLInterface.h"
#include "Node.h"

//using namespace std;

class AVL : public AVLInterface
{
public:
    AVL() {root = NULL;}
    virtual ~AVL() {clear();}
    
    NodeInterface * getRootNode() const;
    
    bool add(int data); //recursively calls insert
    
    bool insert(Node*&, int data);
    
    bool remove(int item); //recursively calls remove
    
    bool erase(Node*&, int data);
    
    void clear();
    
    bool find(int item); //recursively calls search
    
    bool search(Node*& local_root, int target);
    
    void rotateRight(Node*& n);
    
    void rotateLeft(Node*& n);
    
    void balance(Node*& n);
    
    void balToLeft(Node*& n);
    
    void balToRight(Node*& n);
    
private:
    Node* root;
};
