//
//  main.cpp
//  CS 235 Spring 2017 Midterm
//
//  Created by Haley Dennis on 5/26/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include "Magic.h"

using namespace std;

string users_choice = "0";

//Create an object of type Magic, so you can call its functions later
Magic theMagic;
LinkedList<int> theDeck;
LinkedList<int> theWorkingDeck;
LinkedList<int> theList1;
LinkedList<int> theList2;
LinkedList<int> theList3;

string menu(string)
{
    if (users_choice == "1")
    {
        cout << "\n\nThink of a number between 1-21... \nremember that number, because I will guess it by only asking you 3 questions. \nChoose wisely...\n";
        cout << "1 2 3 4 5 6 7 8 9" << endl << "10 11 12 13 14 15" << endl << "16 17 18 19 20 21\n\n" <<endl;
        
        //Populate and Shuffle the deck (linked list)
        theDeck = theMagic.shuffle();
        
        //Steps 3-5 of the trick
        for(int i=0; i<3;)
        {
            theMagic.dealRows(3);
            
            vector<string> cl;
            string line;
            getline(cin, line);
            istringstream iss(line);
            string theRow;
            
            cout << "Which row is your card in? \n";
            cin >> theRow;
            while (iss >> theRow)
            {
                cl.push_back(theRow);
            }
            if (cin.fail() || stoi(theRow) < 0 || stoi(theRow) > 3)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "The row ID you entered does not exist. Press return and try again\n\n\n";
            }
            else
            {
                i++;
                theMagic.consolidate(stoi(theRow));
            }
        }
        
        //Print the 11th node in the linked list
        cout << "You chose the number: " << theMagic.returnNumber() << endl;
        
    }
    
/////////////////////////////////////EXTRA CREDIT///////////////////////////////////////////////

    else if (users_choice == "2")
    {
        vector<string> cl;
        string line;
        getline(cin, line);
        istringstream iss(line);
        int theRange = 0;
        int numRows = 0;
        
        cout << "Choose your range: " << endl;
        cin >> theRange;
        while (iss >> theRange)
        {
            cl.push_back(to_string(theRange));
        }
        if (cin.fail() || theRange < 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The range ID you entered does not work. Press return and try again\n\n\n";
        }
        else
        {
            vector<string> cl;
            string line;
            getline(cin, line);
            istringstream iss(line);
            
            cout << "Choose your number of rows: " << endl;
            cin >> numRows;
            while (iss >> numRows)
            {
                cl.push_back(to_string(numRows));
            }
            if (cin.fail() || numRows < 0)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "The row ID you entered does not work. Press return and try again\n\n\n";
            }
            else
            {
                //Populate and Shuffle the deck (linked list)
                theDeck = theMagic.extraShuffle(theRange);
            }
        }
        
        //Steps 3-5 of the trick
        //Here is the algorithm to calculate the number of iterations:
        //Iteration 1= (theRange/numRows)
        //Iteration 2= (Iteration1/numRows)
        //Iteration 3= (Iteration2/numRows)
        for(int i=theRange; i != 1; i = (i/numRows))
        {
            theMagic.dealRows(numRows);
            
            vector<string> cl;
            string line;
            getline(cin, line);
            istringstream iss(line);
            string theRow;
            
            cout << "Which row is your card in? \n";
            cin >> theRow;
            while (iss >> theRow)
            {
                cl.push_back(theRow);
            }
            if (cin.fail() || stoi(theRow) < 0 || stoi(theRow) > 3)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "The row ID you entered does not exist. Press return and try again\n\n\n";
            }
            else
            {
                i++;
                theMagic.consolidate(stoi(theRow));
            }
        }
        
        //Print the 11th node in the linked list
        cout << "You chose the number: " << theMagic.returnNumber() << endl;
        
/////////////////////////////////////END EXTRA CREDIT///////////////////////////////////////////////
    }
    //Quit gracefully
    else if (users_choice == "3")
    {
        cout << "Exiting the program\n";
        exit (0);
    }
    else
    {
        cout << "Try using an input between 1-3.\n\n\n";
    }
    return "return to menu";
};

int main(int argc, const char * argv[])
{
    while (users_choice != "3")
    {
        cout << "Welcome to the Main Menu! What would you like to do?\n" << endl;
        cout << "1. See a Magic Trick\n";
        cout << "2. Extra Credit Magic Trick\n";
        cout << "3. Quit.\n";
        cin >> users_choice;
        menu(users_choice);
    }
}
