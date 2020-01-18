//
//  Stack.h
//  Lab4
//
//  Created by Haley Dennis on 3/13/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include "LinkedList.h"

template<class T>

class stack
{
private:
    LinkedList<T> sGarage;
    
public:
    virtual bool theStackDuplicateCheck (int value)
    {
        return sGarage.checkForDuplicates(value);
    }
    virtual bool stackValueCheck (int value)
    {
        return sGarage.checkForDuplicates(value);
    }
    //functions
    virtual bool addToTheStack(int currCar)
    {
        sGarage.insertHead(currCar);
        return true;
    }
    /**
     * Removes the first car in the stack and makes it the current car.
     * Does nothing if there is already a current car or if the stack already empty.
     *
     * @return true if the car is successfully removed from the stack; false otherwise
     */
    virtual bool removeFromTheStack()
    {
        sGarage.remove(sGarage.at(0));
        return true;
    }
    
    /**
     * Returns the ID of the first car in the stack.
     *
     * @return the ID of the first car in the stack; -1 if the stack is empty
     */
    virtual int showTopOfTheStack()
    {
        return sGarage.at(0);
    }
    
    /**
     * Returns the number of cars in the stack.
     *
     * @return the number of cars in the stack
     */
    virtual int showSizeOfTheStack()
    {
        return sGarage.size();
    }
    
};




#endif /* Stack_h */
