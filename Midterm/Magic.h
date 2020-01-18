//
//  Magic.h
//  CS 235 Spring 2017 Midterm
//
//  Created by Haley Dennis on 5/27/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//
#ifndef Magic_h
#define Magic_h
#pragma once
#include "LinkedList.h"
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
//#include "StationInterfaceExtra.h"


using namespace std;
/*
extern LinkedList<int> deck;
extern LinkedList<int> workingDeck;
extern LinkedList<int> list1;
extern LinkedList<int> list2;
extern LinkedList<int> list3;
*/
//class Magic : public StationInterfaceExtra

class Magic
{
private:

public:
    LinkedList<int> deck;
    LinkedList<int> workingDeck;
    LinkedList<int> list1;
    LinkedList<int> list2;
    LinkedList<int> list3;
    Magic()
    {
        srand((unsigned)time(NULL));
    }
    virtual ~Magic(){deck.clear();workingDeck.clear();list1.clear();list2.clear();list3.clear();}

    LinkedList<int> shuffle();

    void dealRows(int);

    void consolidate(int);
    
    int returnNumber();
    
    
    //EXTRA CREDIT
    LinkedList<int> extraShuffle(int);

 
};
#endif
