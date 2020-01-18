//  CS 235 Spring 2017 Midterm
//
//  Created by Haley Dennis on 5/27/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//
#pragma once
#include <string>
#include "LinkedListInterface.h"
#include <iostream>
#include <sstream>

using namespace std;



template<class T>
class LinkedList : public LinkedListInterface<T>
{
public:
    struct node
    {
        T data;
        
        node* next;
        node* prev;
        node(): next(NULL), prev(NULL){}
    };
    
    int listsize;
    node* head;
    node* tail;
    
    bool checkForDuplicates(T value)
    {
        //set the head as the first node to be checked
        node* current =head;
        
        //while the node is not pointing to NULL, iterate through the list
        while (current != NULL)
        {
            //if the node's value is equal to the node's data that we passed in return true
            if (current->data == value)
            {
                return true;
            }
            //otherwise, we will set the node we are looking at to the next node (iterating through the list)
            else
            {
                current = current->next;
            }
        }
        return false;
    };
    
    LinkedList() : head(NULL), tail(NULL), listsize(0) {};
    ~LinkedList(){}
    
    //functions:
    /////////////////////////////////////////////////////////INSERT HEAD//////////////////////////////////////////////////////
    //A node with the given value should be inserted at the beginning of the list.
    
    //Do not allow duplicate values in the list.
    
    virtual void insertHead(T value)
    {
        //no search
        //check if head is equal to NULL
        
        if (head == NULL)
        {
            //make a new node
            node* newnode = new node();
            newnode->data = value;
            
            //if the list is empty, make the head and tail equal to this new node you are adding in
            head = newnode;
            tail = newnode;
            
            //increment the size at the end of the function
            listsize++;
            
        }
        else
        {
            //check to see if the new node you are adding in has a duplicate already in the list
            if (checkForDuplicates(value) !=true)
            {
                //if there is not a duplicate, then make the new node
                node* newnode = new node();
                newnode->data = value;
                
                //then make that new node's next equal to head
                newnode->next = head;
                
                //then make head equal to that new node
                head = newnode;
                
                //at the end, increment the size
                listsize++;
            }
        }
    };
    
    /////////////////////////////////////////////////////////INSERT TAIL//////////////////////////////////////////////////////
    //A node with the given value should be inserted at the end of the list.
    
    //Do not allow duplicate values in the list.
    
    virtual void insertTail (T value)
    {
        if (head == NULL)
        {
            insertHead(value);
            return;
        }
        else
        {
            //check to see if the new node you are adding in has a duplicate already in the list
            if (checkForDuplicates(value) != true)
            {
                node* current = head;
                while(current->next != NULL)
                {
                    current= current->next;
                }
                tail = current;
                
                //if there is not a duplicate, then make the new node
                node* newnode = new node();
                newnode->data = value;
                
                //make the (old) tail's next equal to the new node
                tail->next = newnode;
                //newnode->next = tail;
                
                //now make tail equal to the new node
                tail = newnode;
                
                //at the end, increment the size
                listsize++;
                
            }
        }
    };
    
    /////////////////////////////////////////////////////////INSERT AFTER//////////////////////////////////////////////////////
    //A node with the given value should be inserted immediately after the node whose value is equal to insertionNode.
    
    //A node should only be added if the node whose value is equal to insertionNode is in the list. Do not allow duplicate values in the list.
    
    
    virtual void insertAfter(T value, T insertionNode)
    {
        
        //find the insertion node from the value
        //make a temporary node pointer to find the insertion node
        node* temp = head;
        
        //iterate through list until you find the value of insertion node, or until you reach NULL
        while(temp != NULL && insertionNode != temp->data)
        {
            //if those values do not match, go to next node
            temp = temp->next;
        }
        
        //if you reach NULL, return...
        if (temp==NULL)
        {
            return;
        }
        
        if (checkForDuplicates(value) == true)
        {
            return;
        }
            //if you found the insertion node, check if it is the tail, if so, insert it like insert tail
            node* newNode = new node;
            
            //Set newNode's data as data
            newNode->data = value;
            
            //set the new node's next as insertion node's old next
            newNode->next = temp->next;
            
            //set the insertion node's next as the new node we just inserted
            temp->next = newNode;
            
            //increment the size of the list
            listsize++;
        
    };
    
    /////////////////////////////////////////////////////////REMOVE//////////////////////////////////////////////////////
    
    //The node with the given value should be removed from the list.
    
    //The list may or may not include a node with the given value.
    
    virtual void remove(T value)
    {
        node* rnode = head;
        node* previous = NULL;
        
        //traverse through the whole list
        while (rnode != NULL)
        {
            //do this part if the value of the node you are on is the node you want to remove
            if (rnode->data == value)
            {
                //we want to see if the node we if the node we are trying to remove is the head
                if (previous == NULL)
                {
                    head = rnode->next;
                }
                
                //if it is not the head, we will link the node before the one we want to remove to the one after the node to be removed (skipping over the removal node)
                else
                {
                    previous->next = rnode->next;
                }
                
                //delete it; decrement size of the list
                delete rnode;
                listsize--;
                return;
            }
            //Do this part if the node you are on is not the one you want to remove (go to next node)
            previous = rnode;
            rnode = rnode->next;
        }
        return;
    };
    
    
    /////////////////////////////////////////////////////////CLEAR//////////////////////////////////////////////////////
    //clear
    //Remove all nodes from the list.
    
    virtual void clear()
    {
        //iterate through the entire list, no exceptions
        while (head != NULL)
        {
            //we will go through and delete temp and reassign head to the next node to be deleted
            node* temp = head;
            head = head->next;
            delete temp;
        }
        //set everything to NULL/0
        tail = NULL;
        listsize = 0;
        
        
    };
    
    
    /////////////////////////////////////////////////////////T at//////////////////////////////////////////////////////
    //at
    
    //Returns the value of the node at the given index. The list begins at index 0.
    
    //If the given index is out of range of the list, return NULL;
    
    virtual T at(int index)
    {
        
        int count = 0;
        node* temp;
        
        
        //iterate through the list and find the node we're looking for
        
        temp = head;
        while(temp != NULL)
        {
            if (count == index)
            {
                //if the item is the first one in the list, we will return 1 as the index
                return temp->data;
            }
            else
            {
                //if the item is not the first one in the list, we will point to the next node in the list and check that one
                
                temp = temp->next;
                //increment the count
                count++;
            }
        }
        throw std::out_of_range("");
    };
    
    
    /////////////////////////////////////////////////////////SIZE//////////////////////////////////////////////////////
    
    //size
    
    //Returns the number of nodes in the list.
    
    int size()
    {
        return listsize;
    };
    
    /*
     toString
     
     Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
     There should be no trailing space at the end of the string
     
     For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
     "1 2 3 4 5"
     */
    
    virtual string toString()
    {
        node* temp;
        temp = head;
        T value;
        stringstream output;

        while (temp !=NULL)
        {
            if (temp->next == NULL)
            {
                value = temp->data;
                output << value;
                temp = temp->next;
            }
            else
            {
                value = temp->data;
                output << value << " ";
                temp = temp->next;
            }
        }
        return output.str();
    };
};
