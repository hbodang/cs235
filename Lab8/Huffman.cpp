//
//  Huffman.cpp
//  Lab8
//
//  Created by Haley Dennis on 5/24/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//
#include "Huffman.h"

using namespace std;
/*
 Part1 – Create the Tree (30 points)
 Implement the createTree and getTree methods of Huffman Interface.
 Determine the frequency of occurrence of each character, including punctuation marks and whitespace characters, by scanning some sample text. Sample text is a string that is passed in as a parameter.
 
 Follow the “Rules for Your Tree” in the Requirement Notes below when constructing the tree. This test guarantees that your tree conforms to these requirements.
*/
  /**
	* This method is called to generate your tree.  Returns true if the filename given was valid, else false.  Other methods
	* will be used to encode/decode the message or return the tree.
	*
	* @param filename The name of the file containing characters that should be used to create the tree
	*/
bool Huffman::createTree(string filename)
{
    map<char, int> myMap;
    char ch;
    fstream fin(filename);
    //Instantiate/declare (what's the difference?) my priority queue here so we can populate it in this function
    priority_queue<Node*, vector<Node*>, sorter> myPriorityQueue;

    //Try opening the file
    if (!fin.is_open())
    {
        cout << "Could not open file"<< endl;
        return false;
    }
    //The file is open
    else
    {
        cout << "Reading file: " << filename <<endl;

        //Read in all the information from the sample text (not skipping white space) and each piece will be a char
        while (fin >> noskipws >> ch)
        {
            //This will take the char we are at and adds it to the map as a key. If the key is already in the map, it should just increment the value. (initialized to 0)
            //If this doesn't work the way I think, my commented code below should do it?
            myMap[ch]++;
            /*if ((myMap.find(ch)) != myMap.end())
                {myMap[ch]++;}
            else
            {myMap.insert(pair<char,int>(ch,1));}*/
        }
        //Everything should be inserted into our map (unsorted) along with each character's frequencies as the value
    }
    //I will iterate through the map until I reach the end
    auto mapIterator = myMap.begin();
    while (mapIterator != myMap.end())
    {
        //I will create a temporary node pointer that points to a new node that contains the key and value pair. Then I will push that node onto my priority queue, which should prioritize them by least frequency to most. Then I will increment my iterator through the map
        Node* temp = new Node(mapIterator->first, mapIterator->second);
        myPriorityQueue.push(temp);
        mapIterator++;
    }
    /* PRINT PRIORITY QUEUE
    while(myPriorityQueue.size() > 0)
    {
        cout << "Character: " << myPriorityQueue.top()->getCharacter() << endl;
        cout << "Frequency: " << myPriorityQueue.top()->getFrequency() << endl;
        myPriorityQueue.pop();
    }*/
    //Now I need to create a tree from my information in the priority queue
    
    while (myPriorityQueue.size() > 1)
    {
        //Remove the two trees with the smallest weights. Combine them into a new binary tree in which the weight of the tree root is the sum of the weights of its children. Insert the newly created tree back into the priority queue. Each time through the while loop, two nodes are removed from the priority queue and one is inserted. Thus, effectivelly, one tree is removed, and the queue gets smaller with each pass through the loop.
        Node * left = NULL;
        Node * right = NULL;
        left = myPriorityQueue.top();
        myPriorityQueue.pop();
        right = myPriorityQueue.top();
        myPriorityQueue.pop();
        int wl = left->getFrequency();
        int wr = right->getFrequency();
        int frequency = wl + wr;

        Node* temp = new Node('\0', frequency);
        myPriorityQueue.push(temp);
        
    }
    //I'm not sure if this will work: ...
    tree->root = myPriorityQueue.top();
    myPriorityQueue.pop();
    
    return true;
}

/*
 Part 3 – Encode (20 points)
 Implement the encodeMessage method of the HuffmanInterface. Your encoded messages should contain 1's and 0's and nothing else.
*/
/**
	* This method is called to encode a message into 1s and 0s using the tree created by the createTree method.
	*
	* @param toEncode The message to be encoded
	*
	* @return The encoded message, or an empty string if the text could not be encoded
	*/
string Huffman::encodeMessage(string toEncode)
{
    string haley;
    return haley;
}

/*
 Part 4 – Decode (20 points)
 Implement the decodeMessage method of the HuffmanInterface.
*/
/**
	* This method is called to decode a message consisting of 1s and 0s back into characters using the tree that was created by the createTree method.
	*
	* @param toDecode The encoded message (1s and 0s) that should be decoded
	*
	* @return The decoded message, or an empty string if the text could not be decoded
	*/
string Huffman::decodeMessage(string toDecode)
{
    string haley;
    return haley;
}

/**
	* This method is called to return the tree created using the createTree method. It must inherit from TreeInterface.
	*
	* @return A pointer to a TreeInterface. Returns NULL if no tree has been generated.
	*/
TreeInterface * Huffman::getTree()
{
    //Create a TreeInterface *
    TreeInterface * myTree = NULL;
    /*
    //Temporarily cast my tree * to the TreeInterface * I just created
    myTree = (TreeInterface*)tree;
    */
    return myTree;
}

/*
 Part 2 – Make the Encoding (20 points)
 Implement the getEncoding method of the HuffmanInterface .
 Determine a minimal Huffman encoding using the “Rules for Your Tree” in the Requirement Notes below.
 Use a Map data structure to store the encodings with the character as the Key and the encoding as the value mapped to by the key.
*/
/**
	* This method is called to return a map that contains all of the current encodings
	* in the tree that was created by the createTree method.
	*
	* @return A map with the key = char and value = encoding.
	* I.E.
	* If your tree holds: a-01, b-00, c-1
	* Your map would look like this:
	* a->01
	* b->00
	* c->1
	*/
map<char, string> Huffman::getEncodings()
{
    
    map<char, string> encodingMap;
    /*
    string code = NULL;
    
    build_code(tree, code);
     */
    return encodingMap;
}

//Recursive function to get encoding for each character and store them in a map.
//Map Key: character; Map Value: Code
void Huffman::build_code(Tree * tree, string code)
{
    Node * temp = NULL;
    char character = NULL;
    if (tree->is_leaf())
    {
        //set key to character and value to encoding...how?
        character = temp->getCharacter();
        encodingMap[character] = character;
    }
    else
    {
        // Append 0 to code so far and traverse left
        string left_code(code);
        left_code.append(false);
        build_code(tree.get_left_subtree(), left_code);
        // Append 1 to code so far and traverse right
        string right_code(code);
        right_code.append(true);
        build_code(tree.get_right_subtree(), right_code);
    }
}




/*RULES FOR YOUR TREE
 Several different strings will be used to test your solution.For your convenience when testing, we have provided three files: the sample text used above “sample.txt”, a message “message.txt” and the encoding of that message “encMessage.txt” using the tree generated from “sample.txt”.
 For any given text, there could be multiple Huffman trees that are all optimal. This could lead to problems if two parties want to exchange messages that are encoded with trees generated using the same sample text. If each party generates a different, but still optimal, tree, they would end up with nonsensical decoded messages. To avoid this problem for your solution, we will use a set of arbitrary, but necessary, rules that will specify how various aspects of the tree should be handled:
 
 The left branch of a node will use a 0 in the encoding and the right branch will use a 1.
 
 When combining two nodes to make a new node in your tree, the node with the lower frequency should be placed on the left and the node with the higher frequency should be on the right.
 
 In situations where there are duplicate frequencies, a few rules need to be used to create the ordering of your priority queue. Original characters should come before combined nodes. When ordering two original characters, the ordering of the ASCII character set should be used. When ordering two combined nodes, the older node should come first. You can use the sorter struct found in the NodeInterface file (example usage can be found in the comments of that struct) to sort any list of nodes so long as there are no combined nodes in your list. The gcc implementation of sort() cannot use the struct to sort combined nodes in the way that we require, so you will have to implement your own sorted_insert() or sort() function for your list of nodes.
*/
