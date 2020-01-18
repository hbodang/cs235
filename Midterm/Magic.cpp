//
//  Magic.cpp
//  CS 235 Spring 2017 Midterm
//
//  Created by Haley Dennis on 5/27/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//
//#pragma once
#include <stdio.h>
#include "Magic.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

/*
 Shuffle()
 Shuffles the linked list. This is more than just moving around a few nodes. The linked list should be visibly shuffled and every time the algorithm is started, a different shuffled order should result.
 */
LinkedList<int> Magic::shuffle()
{
    //Put 21 nodes into our deck (linked list)
    for (int i=1; i < 22; i++)
    {
        deck.insertTail(i);
    }
    
    int deckSize = 21;
    for (int i = 21; i > 0; i--)
    {
        int random = deck.at(rand()%deckSize);
        workingDeck.insertTail(random);
        deck.remove(random);
        deckSize--;
    }
    
    return workingDeck;
}

/////////////////////////////////////EXTRA CREDIT///////////////////////////////////////////////
LinkedList<int> Magic::extraShuffle(int theRange)
{
    //Put 21 nodes into our deck (linked list)
    for (int i=0; i < theRange; i++)
    {
        deck.insertTail(i);
    }
    
    int deckSize = theRange;
    for (int i = theRange; i > 0; i--)
    {
        int random = deck.at(rand()%deckSize);
        workingDeck.insertTail(random);
        deck.remove(random);
        deckSize--;
    }
    
    return workingDeck;
}
/////////////////////////////////////END EXTRA CREDIT///////////////////////////////////////////////


/*
 DealRows(int)
 Step 3 of the algorithm. Creates three new linked lists from one single linked list by removing one number at a time from the head of the original linked list and adding it to the tail of one of the new linked lists starting from the first new linked list, then the second, then the third, and going back to the first until all nodes have been removed from the original linked list. If doing the extra credit activity (see below), the input parameter is the number of new linked lists being created.
 */
void Magic::dealRows(int)
{
    while (workingDeck.size() != 0)
    {
        list1.insertTail(workingDeck.at(0));
        workingDeck.remove(workingDeck.at(0));
        list2.insertTail(workingDeck.at(0));
        workingDeck.remove(workingDeck.at(0));
        list3.insertTail(workingDeck.at(0));
        workingDeck.remove(workingDeck.at(0));
    }
    cout << "List 1: " << list1.toString() << endl;
    cout << "List 2: " << list2.toString() << endl;
    cout << "List 3: " << list3.toString() << endl;
}



/*
 Consolidate(int)
 Step 5 of the algorithm. Appends each linked list to the tail of another until one single linked list is created. The input parameter is the number of the linked list that contains the user’s number. This linked list must be placed in the center. If doing the extra credit activity where there could be more than three linked lists, make sure that the linked list containing the user’s number is still placed in the center, not just the second position as it would be with three linked lists.
 */
void Magic::consolidate(int theRow)
{
    if (theRow == 1)
    {
        while (list2.size() != 0)
        {
            workingDeck.insertTail(list2.at(0));
            list2.remove(list2.at(0));
        }
        while (list1.size() != 0)
        {
            workingDeck.insertTail(list1.at(0));
            list1.remove(list1.at(0));
        }
        while (list3.size() != 0)
        {
            workingDeck.insertTail(list3.at(0));
            list3.remove(list3.at(0));
        }
    }
    else if (theRow == 2)
    {
        while (list1.size() != 0)
        {
            workingDeck.insertTail(list1.at(0));
            list1.remove(list1.at(0));
        }
        while (list2.size() != 0)
        {
            workingDeck.insertTail(list2.at(0));
            list2.remove(list2.at(0));
        }
        while (list3.size() != 0)
        {
            workingDeck.insertTail(list3.at(0));
            list3.remove(list3.at(0));
        }
    }
    else if (theRow == 3)
    {
        while (list2.size() != 0)
        {
            workingDeck.insertTail(list2.at(0));
            list2.remove(list2.at(0));
        }
        while (list3.size() != 0)
        {
            workingDeck.insertTail(list3.at(0));
            list3.remove(list3.at(0));
        }
        while (list1.size() != 0)
        {
            workingDeck.insertTail(list1.at(0));
            list1.remove(list1.at(0));
        }
    }
    else
    {
        cout << "The row ID you entered does not exist. Please enter a positive existing row number. Returning to menu...\n\n\n";
    }
}

int Magic::returnNumber()
{
    return workingDeck.at(10);
}
