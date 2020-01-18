//
//  Station.h
//  Lab4
//
//  Created by Haley Dennis on 3/13/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#ifndef Station_h
#define Station_h
#pragma once
#include <string>
#include "StationInterfaceExtra.h"
#include <iostream>
#include <sstream>
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "LinkedList.h"
#include "IRDeque.h"
#include "ORDeque.h"

using namespace std;
stack<int> theStack;
queue<int> theQueue;
deque<int> theDeque;
IRdeque<int> theIRdeque;
ORdeque<int> theORdeque;

//template<class T>
//class Station : public StationInterfaceExtra<T>
class Station : public StationInterfaceExtra
{
private:
    int currentCar = -1;
public:
    Station(){}
    virtual ~Station(){}
    
    
    virtual bool stackDuplicateCheck(int value)
    {
        return theStack.theStackDuplicateCheck(value);
    }
    virtual bool queueDuplicateCheck(int value)
    {
        return theQueue.theQueueDuplicateCheck(value);
    }
    virtual bool dequeDuplicateCheck(int value)
    {
        return theDeque.theDequeDuplicateCheck(value);
    }
    virtual bool valueCheck(int theValue)
    {
        if (theValue == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    
    //Part 1--------------------------------------------------------------
    /**
     * Let another car arrive at the station and become the current car.
     * Do not allow a new car to arrive if any of the following conditions apply:
     * 1.	There is already a current car
     * 2.	The new car's ID already exists in any structure
     * 3.	The new car's ID is negative
     *
     @param car the ID of the car arriving at the station
     @return true if the car successfully arrived; false otherwise
     */
    virtual bool addToStation(int car)
    {
        //There is a car in the station, because the currentCar ID is not equal to -1
        if (currentCar != -1)
        {
            //Checking to see if they are trying to put a car in the station that is alrady in a garage
            if (stackDuplicateCheck(car) == true || queueDuplicateCheck(car) == true || theDeque.theDequeDuplicateCheck(car) == true || theIRdeque.theIRDequeDuplicateCheck(car) == true|| theORdeque.theORdequeDuplicateCheck(car) == true)
            {
                cout << "That car ID is already in a garage. Please try another number. ";
                return false;
            }
            cout << "Cannot add another car to the station until the current car in the station is sent to a garage. Returning to main menu.";
            return false;
        }
        //There is not a car in the station because the current Car ID is equal to -1
        else// if (currentCar == -1)
        {
            //Checking to see if they are trying to put a car in the station that is alrady in a garage
            if (stackDuplicateCheck(car) == true || queueDuplicateCheck(car) == true || theDeque.theDequeDuplicateCheck(car) == true || theIRdeque.theIRDequeDuplicateCheck(car) == true|| theORdeque.theORdequeDuplicateCheck(car) == true)
            {
                cout << "That car ID is already in a garage. Please try another number. Returning to main menu.";
                return false;
            }
            // If there is no car in the station, and the car ID they want to enter does not already exist in a garage, then they can add it to the station
            else
            {
                currentCar = car;
                return true;
            }
        }
    }

    /**
     * Returns the ID of the current car.
     * Return -1 if there is no current car.
     *
     * @return the ID of the current car; -1 if there is no current car
     */
    virtual int showCurrentCar()
    {
        //If the currentCar ID is -1, there is no current car
        if (currentCar == -1)
        {
            return -1;
        }
        
        //Otherwise, return the currentCar ID
        else
        {
            return currentCar;
        }
    }
    
    /**
     * Removes the current car from the station.
     * Does nothing if there is no current car.
     *
     * @return true if the current car successfully left; false otherwise
     */
    virtual bool removeFromStation()
    {
        if (currentCar != -1)
        {
            currentCar = -1;
            return true;
        }
        else
        {
            //Current car is already set to -1
            //"Does nothing if there is no current car" does this mean that I should return true?
            return false;
        }
    }
    
    //Part 2--------------------------------------------------------------
    /**
     * Adds the current car to the stack.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the stack is already full.
     *
     * @return true if the car is successfully added to the stack; false otherwise
     */
    virtual bool addToStack()
    {
        if ( theStack.showSizeOfTheStack() < 5 )
        {
            theStack.addToTheStack(currentCar);
            currentCar = -1;
            return true;
        }
        else
        {
            cout << "The stack garage is at maximum capacity (5 cars). Please remove one before trying to add another.";
            return false;
        }
    }
    
    /**
     * Removes the first car in the stack and makes it the current car.
     * Does nothing if there is already a current car or if the stack already empty.
     *
     * @return true if the car is successfully removed from the stack; false otherwise
     */
    virtual bool removeFromStack()
    {
        if (currentCar == -1)
        {
            currentCar = theStack.showTopOfTheStack();
            theStack.removeFromTheStack();
            return true;
        }
        else
        {
            theStack.removeFromTheStack();
            return true;
        }
    }
    
    /**
     * Returns the ID of the first car in the stack.
     *
     * @return the ID of the first car in the stack; -1 if the stack is empty
     */
    virtual int showTopOfStack()
    {
        return theStack.showTopOfTheStack();
    }
    
    /**
     * Returns the number of cars in the stack.
     *
     * @return the number of cars in the stack
     */
    virtual int showSizeOfStack()
    {
        return theStack.showSizeOfTheStack();
    }
    
    //Part 3--------------------------------------------------------------
    /**
     * Adds the current car to the queue.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the queue is already full.
     *
     * @return true if the car is successfully added to the queue; false otherwise
     */
    virtual bool addToQueue()
    {
        if ( theQueue.showSizeOfTheQueue() < 5 )
        {
            theQueue.addToTheQueue(currentCar);
            currentCar = -1;
            return true;
        }
        else
        {
            cout << "The queue garage is at maximum capacity (5 cars). Please remove one before trying to add another.";
            return false;
        }
        
    }
    
    /**
     * Removes the first car in the queue and makes it the current car.
     * Does nothing if there is already a current car or if the queue already empty.
     *
     * @return true if the car is successfully removed from the queue; false otherwise
     */
    virtual bool removeFromQueue()
    {
        if (currentCar == -1)
        {
            currentCar = theQueue.showTopOfTheQueue();
            theQueue.removeFromTheQueue();
            return true;
        }
        else
        {
            theQueue.removeFromTheQueue();
            return true;
        }
    }
    
    /**
     * Returns the ID of the first car in the queue.
     *
     * @return the ID of the first car in the queue; -1 if the queue is empty
     */
    virtual int showTopOfQueue()
    {
        return theQueue.showTopOfTheQueue();
    }
    
    /**
     * Returns the number of cars in the queue.
     *
     * @return the number of cars in the queue
     */
    virtual int showSizeOfQueue()
    {
        return theQueue.showSizeOfTheQueue();
    }
    
    //Part 4--------------------------------------------------------------
    /**
     * Adds the current car to the deque on the left side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the deque is already full.
     *
     * @return true if the car is successfully added to the deque; false otherwise
     */
    virtual bool addToDequeLeft()
    {
        if (theDeque.showSizeOfTheDeque() < 5)
        {
            theDeque.addToTheDequeLeft(currentCar);
            currentCar = -1;
            return true;
        }
        else
        {
            cout << "The deque garage is at maximum capacity (5 cars). Please remove one before trying to add another.";
            return false;
        }
    }
    
    /**
     * Adds the current car to the deque on the right side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the deque is already full.
     *
     * @return true if the car is successfully added to the deque; false otherwise
     */
    virtual bool addToDequeRight()
    {
        if (theDeque.showSizeOfTheDeque() < 5)
        {
            theDeque.addToTheDequeRight(currentCar);
            currentCar = -1;
            return true;
        }
        else
        {
            cout << "The deque garage is at maximum capacity (5 cars). Please remove one before trying to add another.";
            return false;
        }
    }
    
     /*
     * Removes the leftmost car in the deque and makes it the current car.
     * Does nothing if there is already a current car or if the deque already empty.
     * @return true if the car is successfully removed from the deque; false otherwise
     */
    virtual bool removeFromDequeLeft()
    {
        if (currentCar == -1)
        {
            currentCar = theDeque.showTopOfTheDequeLeft();
            theDeque.removeFromTheDequeLeft();
            return true;
        }
        else
        {
            theDeque.removeFromTheDequeLeft();
            return true;
        }
    }
    
     /*
     * Removes the rightmost car in the deque and makes it the current car.
     * Does nothing if there is already a current car or if the deque already empty.
     * @return true if the car is successfully removed from the deque; false otherwise
     */
    virtual bool removeFromDequeRight()
    {
        if (currentCar == -1)
        {
            currentCar = theDeque.showTopOfTheDequeRight();
            theDeque.removeFromTheDequeRight();
            return true;
        }
        else
        {
            theDeque.removeFromTheDequeRight();
            return true;
        }
    }
    
     /*
     * Returns the ID of the leftmost car in the deque.
     * @return the ID of the leftmost car in the deque; -1 if the deque is empty
     */
    virtual int showTopOfDequeLeft()
    {
        return theDeque.showTopOfTheDequeLeft();
    }
    
     /*
     * Returns the ID of the rightmost car in the deque.
     * @return the ID of the rightmost car in the deque; -1 if the deque is empty
     */
    virtual int showTopOfDequeRight()
    {
        return theDeque.showTopOfTheDequeRight();
    }
    
     /*
     * Returns the number of cars in the deque.
     * @return the number of cars in the deque
     */
    virtual int showSizeOfDeque()
    {
        return theDeque.showSizeOfTheDeque();
    }
    
    
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //*********************************************EXTRA CREDIT*********************************************
    
    
    
    
    
    //Input-Restricted Deque----------------------------------------------
    /**
     * Adds the current car to the IRDeque on the left side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the IRDeque is already full.
     *
     * @return true if the car is successfully added to the IRDeque; false otherwise
     */
    virtual bool addToIRDequeLeft()
    {
        if (theIRdeque.showSizeOfTheIRDeque() < 5)
        {
            theIRdeque.addToTheIRDequeLeft(currentCar);
            currentCar = -1;
            return true;
        }
        else
        {
            cout << "The IRdeque garage is at maximum capacity (5 cars). Please remove one before trying to add another.";
            return false;
        }
    }
    
    /**
     * Removes the leftmost car in the IRDeque and makes it the current car.
     * Does nothing if there is already a current car or if the IRDeque already empty.
     *
     * @return true if the car is successfully removed from the IRDeque; false otherwise
     */
    virtual bool removeFromIRDequeLeft()
    {
        if (currentCar == -1)
        {
            currentCar = theIRdeque.showTopOfTheIRDequeLeft();
            theIRdeque.removeFromTheIRDequeLeft();
            return true;
        }
        else
        {
            theIRdeque.removeFromTheIRDequeLeft();
            return true;
        }
    }
    
    /**
     * Removes the rightmost car in the IRDeque and makes it the current car.
     * Does nothing if there is already a current car or if the IRDeque already empty.
     *
     * @return true if the car is successfully removed from the IRDeque; false otherwise
     */
    virtual bool removeFromIRDequeRight()
    {
        if (currentCar == -1)
        {
            currentCar = theIRdeque.showTopOfTheIRDequeRight();
            theIRdeque.removeFromTheIRDequeRight();
            return true;
        }
        else
        {
            theIRdeque.removeFromTheIRDequeRight();
            return true;
        }
    }
    
    /**
     * Returns the ID of the leftmost car in the IRDeque.
     *
     * @return the ID of the leftmost car in the IRDeque; -1 if the IRDeque is empty
     */
    virtual int showTopOfIRDequeLeft()
    {
        return theIRdeque.showTopOfTheIRDequeLeft();
    }
    
    /**
     * Returns the ID of the rightmost car in the IRDeque.
     *
     * @return the ID of the rightmost car in the IRDeque; -1 if the IRDeque is empty
     */
    virtual int showTopOfIRDequeRight()
    {
        return theIRdeque.showTopOfTheIRDequeRight();
    }
    
    /**
     * Returns the number of cars in the IRDeque.
     *
     * @return the number of cars in the IRDeque
     */
    virtual int showSizeOfIRDeque()
    {
        return theIRdeque.showSizeOfTheIRDeque();
    }
    
    //Output-Restricted Deque---------------------------------------------
    /**
     * Adds the current car to the ORDeque on the left side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the ORDeque is already full.
     *
     * @return true if the car is successfully added to the ORDeque; false otherwise
     */
    virtual bool addToORDequeLeft()
    {
        if (theORdeque.showSizeOfTheORDeque() < 5)
        {
            theORdeque.addToTheORDequeLeft(currentCar);
            currentCar = -1;
            return true;
        }
        else
        {
            cout << "The ORdeque garage is at maximum capacity (5 cars). Please remove one before trying to add another.";
            return false;
        }
    }
    
    /**
     * Adds the current car to the ORDeque on the right side.  After this operation, there should be no current car.
     * Does nothing if there is no current car or if the ORDeque is already full.
     *
     * @return true if the car is successfully added to the ORDeque; false otherwise
     */
    virtual bool addToORDequeRight()
    {
        if (theORdeque.showSizeOfTheORDeque() < 5)
        {
            theORdeque.addToTheORDequeRight(currentCar);
            currentCar = -1;
            return true;
        }
        else
        {
            cout << "The ORdeque garage is at maximum capacity (5 cars). Please remove one before trying to add another.";
            return false;
        }
    }
    
    /**
     * Removes the leftmost car in the ORDeque and makes it the current car.
     * Does nothing if there is already a current car or if the ORDeque already empty.
     *
     * @return true if the car is successfully removed from the ORDeque; false otherwise
     */
    virtual bool removeFromORDequeLeft()
    {
        if (currentCar == -1)
        {
            currentCar = theORdeque.showTopOfTheORDequeLeft();
            theORdeque.removeFromTheORDequeLeft();
            return true;
        }
        else
        {
            theORdeque.removeFromTheORDequeLeft();
            return true;
        }
    }
    
    /**
     * Returns the ID of the leftmost car in the ORDeque.
     *
     * @return the ID of the leftmost car in the ORDeque; -1 if the ORDeque is empty
     */
    virtual int showTopOfORDequeLeft()
    {
        return theORdeque.showTopOfTheORDequeLeft();
    }
    
    /**
     * Returns the number of cars in the ORDeque.
     *
     * @return the number of cars in the ORDeque
     */
    virtual int showSizeOfORDeque()
    {
        return theORdeque.showSizeOfTheORDeque();
    }
};

#endif /* Station_h */
