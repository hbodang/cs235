//
//  Queue.h
//  Lab4
//
//  Created by Haley Dennis on 3/13/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#include "LinkedList.h"

template<class T>

class queue
{
private:
    LinkedList<T> qGarage;
    
public:
    virtual bool theQueueDuplicateCheck (int value)
    {
        return qGarage.checkForDuplicates(value);
    }
    /**
     * Adds the current car to the queue.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the queue is already full.
     *
     * @return true if the car is successfully added to the queue; false otherwise
     */
    virtual bool addToTheQueue(int currCar)
    {
        qGarage.insertHead(currCar);
        return true;
    }
    
    /**
     * Removes the first car in the queue and makes it the current car.
     * Does nothing if there is already a current car or if the queue already empty.
     *
     * @return true if the car is successfully removed from the queue; false otherwise
     */
    virtual bool removeFromTheQueue()
    {
        //cout << "this is what I'm trying to remove: " << qGarage.at(qGarage.size() -1);
        qGarage.remove(qGarage.at(qGarage.size() -1));
        return true;
    }
    
    /**
     * Returns the ID of the first car in the queue.
     *
     * @return the ID of the first car in the queue; -1 if the queue is empty
     */
    virtual int showTopOfTheQueue()
    {
        return qGarage.at(qGarage.size() -1);
    }
    
    /**
     * Returns the number of cars in the queue.
     *
     * @return the number of cars in the queue
     */
    virtual int showSizeOfTheQueue()
    {
        return qGarage.size();
    }
};

#endif /* Queue_h */
