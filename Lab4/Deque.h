//
//  Deque.h
//  Lab4
//
//  Created by Haley Dennis on 3/13/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#ifndef Deque_h
#define Deque_h
#include "LinkedList.h"

template<class T>

class deque
{
private:
    LinkedList<T> dGarage;
    
public:
    virtual bool theDequeDuplicateCheck (int value)
    {
        return dGarage.checkForDuplicates(value);
    }

    /**
     * Adds the current car to the deque on the left side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the deque is already full.
     *
     * @return true if the car is successfully added to the deque; false otherwise
     */
    virtual bool addToTheDequeLeft(int currCar)
    {
        dGarage.insertHead(currCar);
        return true;
    }
    
    /**
     * Adds the current car to the deque on the right side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the deque is already full.
     *
     * @return true if the car is successfully added to the deque; false otherwise
     */
    virtual bool addToTheDequeRight(int currCar)
    {
        dGarage.insertTail(currCar);
        return true;
    }
    
    /**
     * Removes the leftmost car in the deque and makes it the current car.
     * Does nothing if there is already a current car or if the deque already empty.
     *
     * @return true if the car is successfully removed from the deque; false otherwise
     */
    virtual bool removeFromTheDequeLeft()
    {
        //cout << "this is what I'm trying to remove: " << dGarage.at(0);
        dGarage.remove(dGarage.at(0));
        return true;
    }
    
    /**
     * Removes the rightmost car in the deque and makes it the current car.
     * Does nothing if there is already a current car or if the deque already empty.
     *
     * @return true if the car is successfully removed from the deque; false otherwise
     */
    virtual bool removeFromTheDequeRight()
    {
        //cout << "this is what I'm trying to remove: " << dGarage.at(dGarage.size() -1);
        dGarage.remove(dGarage.at(dGarage.size() -1));
        return true;
    }
    
    /**
     * Returns the ID of the leftmost car in the deque.
     *
     * @return the ID of the leftmost car in the deque; -1 if the deque is empty
     */
    virtual int showTopOfTheDequeLeft()
    {
        return dGarage.at(0);
    }
    
    /**
     * Returns the ID of the rightmost car in the deque.
     *
     * @return the ID of the rightmost car in the deque; -1 if the deque is empty
     */
    virtual int showTopOfTheDequeRight()
    {
        return dGarage.at(dGarage.size() -1);
    }
    
    /**
     * Returns the number of cars in the deque.
     *
     * @return the number of cars in the deque
     */
    virtual int showSizeOfTheDeque()
    {
        return dGarage.size();
    }
};

#endif /* Deque_h */
