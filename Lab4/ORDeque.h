//
//  ORDeque.h
//  Lab4
//
//  Created by Haley Dennis on 3/22/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#ifndef ORDeque_h
#define ORDeque_h
#include "LinkedList.h"

template<class T>

class ORdeque
{
private:
    LinkedList<T> ORdGarage;
    
public:
    virtual bool theORdequeDuplicateCheck (int value)
    {
        return ORdGarage.checkForDuplicates(value);
    }
    
    /**
     * Adds the current car to theORdeque on the left side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if theORdeque is already full.
     *
     * @return true if the car is successfully added to theORdeque; false otherwise
     */
    virtual bool addToTheORDequeLeft(int currCar)
    {
        ORdGarage.insertHead(currCar);
        return true;
    }
    
    /**
     * Adds the current car to theORdeque on the right side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if theORdeque is already full.
     *
     * @return true if the car is successfully added to theORdeque; false otherwise
     */
    virtual bool addToTheORDequeRight(int currCar)
    {
        ORdGarage.insertTail(currCar);
        return true;
    }
    
    /**
     * Removes the leftmost car in theORdeque and makes it the current car.
     * Does nothing if there is already a current car or if theORdeque already empty.
     *
     * @return true if the car is successfully removed from theORdeque; false otherwise
     */
    virtual bool removeFromTheORDequeLeft()
    {
        //cout << "this is what I'm trying to remove: " << dGarage.at(0);
        ORdGarage.remove(ORdGarage.at(0));
        return true;
    }
    
    /**
     * Returns the ID of the leftmost car in theORdeque.
     *
     * @return the ID of the leftmost car in theORdeque; -1 if theORdeque is empty
     */
    virtual int showTopOfTheORDequeLeft()
    {
        return ORdGarage.at(0);
    }
    
    /**
     * Returns the number of cars in theORdeque.
     *
     * @return the number of cars in theORdeque
     */
    virtual int showSizeOfTheORDeque()
    {
        return ORdGarage.size();
    }
};

#endif /* ORDeque_h */
