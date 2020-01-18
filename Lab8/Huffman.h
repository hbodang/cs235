//
//  Huffman.h
//  Lab8
//
//  Created by Haley Dennis on 5/24/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#pragma once
#include "HuffmanInterface.h"
//#include "NodeInterface.h"
#include "Node.h"
#include "Tree.h"
#include <map>
#include <vector>
#include <sstream>
#include <queue>
#include <deque>
#include <set>
#include <stdexcept>
#include <utility>
#include <typeinfo>
#include <fstream>
#include <iostream>

class Huffman : public HuffmanInterface
{
private:
    //priority_queue <Node*, vector<Node*>, sorter> myPriorityQueue;
    Tree* tree;
    map<char, string> message;
    
public:
    Huffman() {tree = new Tree();}
    virtual ~Huffman() { delete tree; /*message = map*/}

    priority_queue <Node*, vector<Node*>, sorter> myPriorityQueue;

    bool createTree(string filename);
    
    string encodeMessage(string toEncode);
    
    string decodeMessage(string toDecode);
    
    TreeInterface * getTree();
    
    map<char, string> getEncodings();
    
    void build_code(Tree * tree, string code);
    
};

