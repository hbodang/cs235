//
//  main.cpp
//  Lab4
//
//  Created by Haley Dennis on 3/13/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "Station.h"
#include <regex>
#include <sstream>


using namespace std;

string users_choice = "0";


//Create an object of type Station, so you can call its functions later
Station theStation;

//regex regex_pattern2("^[0-9]{1,10000000000000}$");

string menu(string)
{
    //Add a car to the station
    /*
     This option should allow the user to enter a train car represented by a nonnegative
     integer and attempt to add that car to the station. Remember that negative integers are not
     valid train car IDs and train car IDs are unique integers. You should reject any invalid input (if
     it’s not an int, display a message stating that the car could not be added and return to the main
     menu.) If the train car cannot be added to the station the user should be alerted with a
     message explaining that the car could not be added.
    */
    if (users_choice == "1")
    {
        if (theStation.showCurrentCar() != -1)
        {
            cout << "There is already a car in the station. Please add that car to a garage or remove it from the station before adding another car.\n\n\n";
        }
        else
        {
            vector<string> cl;
            string line;
            getline(cin, line);
            istringstream iss(line);
            string theCar;
            
            cout << "Please enter car ID to add: \n";
            cin >> theCar;
            while ( iss >> theCar)
            {
                cl.push_back(theCar);
            }
            //if (cin.fail() || car < 0
            if (cin.fail() || stoi(theCar) < 0/* !(regex_match(theCar,regex_pattern2))*/)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "The car ID you entered was invalid and could not be added. Please enter a positive integer. Returning to menu...\n\n\n";
            }
            else
            {
                theStation.addToStation(stoi(theCar));
            }
        }
    }
    
    //Remove a car from the station
    /*
     This option should remove a car from the station. If the station is empty, this option does
     nothing.
    */
    else if (users_choice == "2")
    {
        theStation.removeFromStation();
    }
    
    //Add a car from the station to a storage facility
    /*
     This option should allow the user to choose from among the data structures (stack,
     queue, or deque) and attempt to add the current car in the station to that data structure. If the
     car cannot be added to the data structure or there is no car in the station, the user should be
     alerted. If the car can be added, it should be moved from the station to the appropriate data
     structure.
    */
    else if (users_choice == "3")
    {
        if (theStation.showCurrentCar() == -1)
        {
            cout << "There is no current car in the station. Please add a car to the station that you can then add to a garage.\n";
        }
        else
        {
            int chosenGarage;
            cout << "Which storage facility would you like to add the current car to?\n";
            cout << "1. Stack\n";
            cout << "2. Queue\n";
            cout << "3. Deque\n";
            cout << "4. IRDeque\n";
            cout << "5. ORDeque\n";
            cin >> chosenGarage;

            if (chosenGarage == 1)
            {
                theStation.addToStack();
            }
            else if (chosenGarage == 2)
            {
                theStation.addToQueue();
            }
            else if (chosenGarage == 3)
            {
                // Ask the user Left or Right?
                int chosenSide;
                cout << "Would you like to add the car to the left or right side of the deque?\n";
                cout << "1. Right\n";
                cout << "2. Left\n";
                cin >> chosenSide;

                if (chosenSide == 1)
                {
                    theStation.addToDequeRight();
                }
                else if (chosenSide == 2)
                {
                    theStation.addToDequeLeft();
                }
                else
                {
                    cin.clear();
                    cin.ignore(800, '\n');
                    cout << "The side you entered was invalid and could not be added. Please enter either 1 for right or 2 for left. Returning to main menu...\n\n\n";
                }
            }
            else if (chosenGarage == 4)
            {
                theStation.addToIRDequeLeft();
            }
            else if (chosenGarage == 5)
            {
                // Ask the user Left or Right?
                int chosenSide;
                cout << "Would you like to add the car to the left or right side of the deque?\n";
                cout << "1. Right\n";
                cout << "2. Left\n";
                cin >> chosenSide;
                
                if (chosenSide == 1)
                {
                    theStation.addToORDequeRight();
                }
                else if (chosenSide == 2)
                {
                    theStation.addToORDequeLeft();
                }
                else
                {
                    cin.clear();
                    cin.ignore(800, '\n');
                    cout << "The side you entered was invalid and could not be added. Please enter either 1 for right or 2 for left. Returning to main menu...\n\n\n";
                }
            }
            // if I make this the if and the rest else ifs, then this does an infinite loop...
            else if (!(cin >> chosenGarage) || chosenGarage < 0)
            {
                cin.clear();
                cin.ignore(800, '\n');
                cout << "The garage ID you entered was invalid and could not be added. Please enter a positive integer. Returning to main menu...\n\n\n";
            }
            else
            {
                cin.clear();
                cin.ignore(800, '\n');
                cout << "The garage ID you entered was invalid and could not be added. Please enter a positive integer. Returning to main menu...\n\n\n";
            }
            
        }
    }
    
    //Remove a car from a storage facility and add it to the station
    /*
     This option should prompt the user for a car number. Then, if that car is available at an
     accessible point in one of the data structures, this should attempt to remove the car from the
     data structure and add it to the station. If the station is already occupied or if the car cannot be
     accessed, this does nothing and alerts the user.
    */
    else if (users_choice == "4")
    {
        if (theStation.showCurrentCar() != -1)
        {
            cout << "There is currently a car in the station. Please remove the car from the station, then you can then remove a car from a garage.\n";
        }
        else
        {
            int chosenCar;
            cout << "Which car would you like to remove from the storage facilities?\n";
            cin >> chosenCar;
            
            
            //Check to see if the user's chosen car is accessible from the stack
            if (theStack.showSizeOfTheStack() > 0 && chosenCar == theStack.showTopOfTheStack())
            {
                theStation.removeFromStack();
                return "Removed.";
            }
            else if (theQueue.showSizeOfTheQueue() > 0 && chosenCar == theQueue.showTopOfTheQueue())
            {
                theStation.removeFromQueue();
                return "Removed.";
            }
            else if (theDeque.showSizeOfTheDeque() > 0 && chosenCar == theDeque.showTopOfTheDequeLeft())
            {
                theStation.removeFromDequeLeft();
                return "Removed.";
            }
            else if (theDeque.showSizeOfTheDeque() > 0 && chosenCar == theDeque.showTopOfTheDequeRight())
            {
                theStation.removeFromDequeRight();
                return "Removed.";
            }
            else if (theIRdeque.showSizeOfTheIRDeque() > 0 && chosenCar == theIRdeque.showTopOfTheIRDequeLeft())
            {
                theStation.removeFromIRDequeLeft();
                return "Removed.";
            }
            else if (theIRdeque.showSizeOfTheIRDeque() > 0 && chosenCar == theIRdeque.showTopOfTheIRDequeRight())
            {
                theStation.removeFromIRDequeRight();
                return "Removed.";
            }
            else if (theORdeque.showSizeOfTheORDeque() > 0 && chosenCar == theORdeque.showTopOfTheORDequeLeft())
            {
                theStation.removeFromORDequeLeft();
                return "Removed.";
            }
            else if (!(cin >> chosenCar) || chosenCar < 0)
            {
                cin.clear();
                cin.ignore(800, '\n');
                cout << "The car ID you entered was inaccessible or does not exist and could not be removed from any of the garages. Please check which cars are accessible, using option 5. Returning to main menu...\n\n\n";
                return "string";
            }
            else
            {
                cout << "The car ID you entered was inaccessible or does not exist and could not be removed from any of the garages. Please check which cars are accessible, using option 5. Returning to main menu.\n\n\n";
                return "string";
            }
        }
    }
    //Display the cars currently accessible in the station and storage facilities
    /*
     This option should display all of the available cars in the station and the storage facilities.
     When a user selects this option, a list of the data structures and the cars accessible from those
     data structures should be displayed. For example, you might display:
     Stack: 7
     Deque: 6, 5
     Queue: 4
     Station: empty
    */
    else if (users_choice == "5")
    {
        if (theStack.showSizeOfTheStack() == 0)
        {
            cout << "Stack: empty\n";
        }
        else if (theStack.showSizeOfTheStack() != 0)
        {
            cout << "Stack: " << theStack.showTopOfTheStack() << "\n";
        }
        if (theQueue.showSizeOfTheQueue() == 0)
        {
            cout << "Queue: empty\n";
        }
        else if (theQueue.showSizeOfTheQueue() != 0)
        {
            cout << "Queue: " << theQueue.showTopOfTheQueue() << "\n";
        }
        if (theDeque.showSizeOfTheDeque() == 0)
        {
            cout << "Deque: empty\n";
        }
        else if (theDeque.showSizeOfTheDeque() != 0)
        {
            if (theDeque.showSizeOfTheDeque() == 1)
            {
                cout << "Deque: " << theDeque.showTopOfTheDequeLeft() << "\n";
            }
            else
            {
                cout << "Deque: " << theDeque.showTopOfTheDequeLeft() << ", " << theDeque.showTopOfTheDequeRight() << "\n";
            }
        }
        if (theIRdeque.showSizeOfTheIRDeque() == 0)
        {
            cout << "IRDeque: empty\n";
        }
        else if (theIRdeque.showSizeOfTheIRDeque() != 0)
        {
            if (theIRdeque.showSizeOfTheIRDeque() == 1)
            {
                cout << "IRDeque: " << theIRdeque.showTopOfTheIRDequeLeft() << "\n";
            }
            else
            {
                cout << "IRDeque: " << theIRdeque.showTopOfTheIRDequeLeft() << ", " << theIRdeque.showTopOfTheIRDequeRight() << "\n";
            }
        }
        if (theORdeque.showSizeOfTheORDeque() == 0)
        {
            cout << "ORDeque: empty\n";
        }
        else if (theORdeque.showSizeOfTheORDeque() != 0)
        {
            if (theORdeque.showSizeOfTheORDeque() == 1)
            {
                cout << "ORDeque: " << theORdeque.showTopOfTheORDequeLeft() << "\n";
            }
            else
            {
                cout << "ORDeque: " << theORdeque.showTopOfTheORDequeLeft() << "\n";
            }
        }
        if (theStation.showCurrentCar() == -1)
        {
            cout << "Station: empty\n";
        }
        else
        {
            cout << "Station: " << theStation.showCurrentCar() << "\n";
        }
    }
    
    //Quit gracefully
    else if (users_choice == "6")
    {
        cout << "Choo choo ciao!\n";
        //needs to be more graceful
        //return 0;
        exit (0);
    }
    else
    {
        cout << "Try using an input between 1-6.\n\n\n";
    }
    return "return to menu";
};

int main(int argc, const char * argv[])
{
    while (users_choice != "6")
    {
        cout << "Welcome to the Railroad! What would you like to do?\n" << endl;
        cout << "1. Add a car to the station\n";
        cout << "2. Remove a car from the station\n";
        cout << "3. Add a car from the station to a storage facility\n";
        cout << "4. Remove a car from a storage facility and add it to the station\n";
        cout << "5. Display the cars currently accessible in the station and storage facilities\n";
        cout << "6. Quit.\n";
        cin >> users_choice;
        menu(users_choice);
    }
}
