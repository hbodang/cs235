//
//  IRDeque.h
//  Lab4
//
//  Created by Haley Dennis on 3/22/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#ifndef IRDeque_h
#define IRDeque_h

#include "LinkedList.h"

template<class T>

class IRdeque
{
private:
    LinkedList<T> IRdGarage;
    
public:
    virtual bool theIRDequeDuplicateCheck (int value)
    {
        return IRdGarage.checkForDuplicates(value);
    }
    
    /**
     * Adds the current car to theIRdeque on the left side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if theIRdeque is already full.
     *
     * @return true if the car is successfully added to theIRdeque; false otherwise
     */
    virtual bool addToTheIRDequeLeft(int currCar)
    {
        IRdGarage.insertHead(currCar);
        return true;
    }
    
    /**
     * Removes the leftmost car in theIRdeque and makes it the current car.
     * Does nothing if there is already a current car or if theIRdeque already empty.
     *
     * @return true if the car is successfully removed from theIRdeque; false otherwise
     */
    virtual bool removeFromTheIRDequeLeft()
    {
        //cout << "this is what I'm trying to remove: " << dGarage.at(0);
        IRdGarage.remove(IRdGarage.at(0));
        return true;
    }
    
    /**
     * Removes the rightmost car in theIRdeque and makes it the current car.
     * Does nothing if there is already a current car or if theIRdeque already empty.
     *
     * @return true if the car is successfully removed from theIRdeque; false otherwise
     */
    virtual bool removeFromTheIRDequeRight()
    {
        //cout << "this is what I'm trying to remove: " << dGarage.at(dGarage.size() -1);
        IRdGarage.remove(IRdGarage.at(IRdGarage.size() -1));
        return true;
    }
    
    /**
     * Returns the ID of the leftmost car in theIRdeque.
     *
     * @return the ID of the leftmost car in theIRdeque; -1 if theIRdeque is empty
     */
    virtual int showTopOfTheIRDequeLeft()
    {
        return IRdGarage.at(0);
    }
    
    /**
     * Returns the ID of the rightmost car in theIRdeque.
     *
     * @return the ID of the rightmost car in theIRdeque; -1 if theIRdeque is empty
     */
    virtual int showTopOfTheIRDequeRight()
    {
        return IRdGarage.at(IRdGarage.size() -1);
    }
    
    /**
     * Returns the number of cars in theIRdeque.
     *
     * @return the number of cars in theIRdeque
     */
    virtual int showSizeOfTheIRDeque()
    {
        return IRdGarage.size();
    }
};

#endif /* IRIRdeque_h */
