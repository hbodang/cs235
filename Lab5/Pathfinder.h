//
//  Pathfinder.h
//  Lab5
//
//  Created by Haley Dennis on 3/30/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#ifndef Pathfinder_h
#define Pathfinder_h
#include "PathfinderInterface.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Pathfinder : public PathfinderInterface
{
private:
    string maze [5][5][5] = {{{"1"}}};
    vector<string> returnPath;
public:

    string stringMaze;
    
    Pathfinder()
    {
        srand((unsigned)time(NULL));
        
        for(int z = 0; z < 5; z++)
        {
            for(int y = 0; y < 5; y++)
            {
                for(int x = 0; x < 5; x++)
                {
                    maze [x][y][z] = "1";
                }
            }
        }
    }
    //virtual ~Pathfinder(){}
    
    
    //Part 1-----------------------------------------------------------------------------------
    /*
    * toString
    *
    * Returns a string representation of the current maze. Returns a maze of all 1s if no maze
    * has yet been generated or imported.
    *
    * A valid string representation of a maze consists only of 125 1s and 0s (each separated
    * by spaces) arranged in five 5x5 grids (each separated by newlines) with no trailing newline. A valid maze must
    * also have 1s in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).
    *
    * Cell (0, 0, 0) is represented by the first number in the string representation of the
    * maze. Increasing in x means moving toward the east, meaning cell (1, 0, 0) is the second
    * number. Increasing in y means moving toward the south, meaning cell (0, 1, 0) is the
    * sixth number. Increasing in z means moving downward to a new grid, meaning cell
    * (0, 0, 1) is the twenty-sixth cell in the maze. Cell (4, 4, 4) is represented by the last number.
    *
    * Returns:		string
    *				A single string representing the current maze
    */
    virtual string toString() const
    {
        string out;
        
        //This three-pronged for loop iterates through the maze and outputs it all to a single string, including spaces and newlines
        for(int z=0;z < 5; z++)
        {
            for(int y=0; y < 5; y++)
            {
                for(int x=0; x < 5; x++)
                {
                    out += maze[x][y][z];
                    if (x != 4)
                    {
                        out += " "; //add in a space after every character except
                    }
                    else if (x == 4)
                    {
                        out += "\n"; //add in a newline at the end of every line
                    }
                }
                if (y ==4 && z < 4)
                {
                    out += "\n"; //add in a newline at the end of every page, but not an extra at the end
                }
            }
        }
        return out;
    }

    /*
        * createRandomMaze
        *
        * Generates a random maze and stores it as the current maze.
        *
        * The generated maze must contain a roughly equal number of 1s and 0s and must have a 1
        * in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).  The generated maze may be
        * solvable or unsolvable, and this method should be able to produce both kinds of mazes.
        */
    
//    Generate Random Mazes (5 points)
//    This will test your createRandomMaze() function and your solveMaze() function.
//    You will be required to generate several random mazes.  Because the mazes will be randomly generated, there is no key_file5 to compare against.  Rather, you should make sure that each generated maze is a valid maze.  Mazes will be tested by calling solveMaze() on the generated mazes.  You must return either a valid path or no path for each maze, and there should be several solvable mazes and several unsolvable mazes in the output.  If you have either no solvable mazes or unsolvable mazes, run the program again until several of each are generated.
    
    virtual void createRandomMaze()
    {
        /*
        Pseudocode:
        Create Random Maze Function:
        srand -> in the constructor for the class in create random maze, I will call the srand function so that the seed isn't the same every time
        */
        //int cell = rand()%1;
        
        string currentMaze[5][5][5];
        
        for(int z = 0; z < 5; z++)
        {
            for(int y = 0; y < 5; y++)
            {
                for(int x = 0; x < 5; x++)
                {
                    currentMaze[x][y][z] = to_string(rand()%2);
                }
            }
        }
        
        //All random mazes created will be valid, but they can either be solvable or unsolvable
        //Make the maze valid by setting the first and last cells to "1"
        currentMaze[0][0][0] = "1";
        currentMaze[4][4][4] = "1";
        
        //Copy our currentMaze over to maze
        for(int z = 0; z < 5; z++)
        {
            for(int y = 0; y < 5; y++)
            {
                for(int x = 0; x < 5; x++)
                {
                    maze[x][y][z] = currentMaze[x][y][z];
                }
            }
        }
        

    }
    //-----------------------------------------------------------------------------------------

    //Part 2-----------------------------------------------------------------------------------
    /*
        * importMaze
        *
        * Reads in a maze from a file with the given file name and stores it as the current maze.
        * Does nothing if the file does not exist or if the file's data does not represent a valid
        * maze.
        *
        * The file's contents must be of the format described above to be considered valid.
        *
        * Parameter:	file_name
        *				The name of the file containing a maze
        * Returns:		bool
        *				True if the maze is imported correctly; false otherwise
        */
    
//    Import Maze (10 points)
//    For this part, you will need to implement your importMaze() and toString() functions.  The importMaze function is described in the PathfinderInterface.h file, but here are some things to note:
//    You will be given a filename for each maze (you must keep the Mazes folder in the working directory of your project).  Valid files will contain representations of mazes, with each cell represented by a 0 or a 1.
//        You must check to make sure that the given file contains valid maze information.  Each maze should consist of exactly 125 1's or 0's.  Mazes may be solvable or unsolvable.
    
    
//    Invalid Import (4 points)
//    This test will check your importMaze() function to make sure that it properly rejects invalid mazes and filenames.  A maze is invalid if it consists of anything other than exactly 125 cells, each represented by either a 0 or a 1.
//        Your current maze should not change during an invalid import.
//        Your maze should consist of all 1's if no maze has yet been imported.
    
    virtual bool importMaze(string file_name)
    {
        //Take the string of the file_name that is given to this function and put it into an ifstream, then read that ifstream into a single string, stringMaze, then read those into the 3D array, maze
        ifstream input(file_name);
        string tempString= "";
        string currentMaze[5][5][5];
        
        if (!input.is_open())
        {
            return false;
        }
        else
        {
            for(int z = 0; z < 5; z++)
            {
                for(int y = 0; y < 5; y++)
                {
                    for(int x = 0; x < 5; x++)
                    {
                        //if the file is not long enough, break and return false
                        if(input.eof())
                            break;
                        
                        input >> stringMaze;
                        //check if all the entries are 0s or 1s
                        if(stringMaze == "1" || stringMaze == "0")
                        {
                            tempString += stringMaze;
                            currentMaze[x][y][z] = stringMaze;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
            //Is the maze file given too long? Return false
            if (!input.eof())
                return false;
            
            //if the length of the maze is the correct size (125) and the first and last squares are 1's then we will load our temporary maze into the maze for use outside of this function
            else if (tempString.length() == 125 && tempString[0] == '1' && tempString[124] == '1')
            {
                for(int z = 0; z < 5; z++)
                {
                    for(int y = 0; y < 5; y++)
                    {
                        for(int x = 0; x < 5; x++)
                        {
                            maze[x][y][z] = currentMaze[x][y][z];
                        }
                    }
                }
                return true;
            }
            else
                return false;
        }

    }
    //-----------------------------------------------------------------------------------------

    //Part 3-----------------------------------------------------------------------------------
    /*
        * solveMaze
        *
        * Attempts to solve the current maze and returns a solution if one is found.
        *
        * A solution to a maze is a list of coordinates for the path from the entrance to the exit
        * (or an empty vector if no solution is found). This list cannot contain duplicates, and
        * any two consecutive coordinates in the list can only differ by 1 for only one
        * coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
        * in the solution. Each string in the solution vector must be of the format "(x, y, z)",
        * where x, y, and z are the integer coordinates of a cell.
        *
        * Understand that most mazes will contain multiple solutions
        *
        * Returns:		vector<string>
        *				A solution to the current maze, or an empty vector if none exists
        */
    
//    Solvable Mazes (15 points)
//    This will test your algorithm against several solvable mazes.  Each given maze should be properly imported and solved as described in the PathfinderInterface.h file.
//    A valid path is one which starts at the entrance (0, 0, 0) and ends at the exit (4, 4, 4) and does not contain any cycles. When moving between cells, the divers can only move up, down, left, right, forward, and backwards one cell at a time. No diagonals are allowed.
    
//    Unsolvable Mazes (4 points)
//    This will test your algorithm against several unsolvable mazes.
    
    virtual vector<string> solveMaze()
    {
        //solveMaze calls recursive function called "solve"
        
        //make a temporary 3D array for use inside this function
        string tempMaze[5][5][5];
        
        returnPath.clear();
        
        //Copy maze information to temp maze
        for(int h = 0; h < 5; h++)
        {
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    tempMaze[j][i][h] = maze[j][i][h];
                }
            }
        }

        //Call the solve function on the first cell
        solve(tempMaze,0,0,0);
        
        //If the maze is unsolvable, the returnpath should be blank
        return returnPath;
    }
    
    bool solve(string tempMaze[5][5][5], int x, int y, int z)
    {
        //Assume that the cell we are on is part of the return path until we prove its not
        //Push back the cell's coordinates to the returnPath
        //If it is not part of the return path, we will pop back the coordinate at the end
        
        
        //Make the coordinates strings so we can push it back on the vector of strings
        string a = to_string(x);
        string b = to_string(y);
        string c = to_string(z);
        string coordinate = "(" + a + ", " + b + ", " + c + ")";
        returnPath.push_back(coordinate);
        
        //Base case: the exit cell (bottom right; (4,4,4))
        if (x == 4 && y == 4 && z == 4)
            return true;
        
        //Is the cell out of bounds?
        else if(x < 0 || y < 0 || z < 0 || x > 4 || y > 4 || z > 4)
        {
            returnPath.pop_back();
            return false;
        }
        //Is the cell a 0?
        else if(tempMaze[x][y][z] != "1")
        {
            returnPath.pop_back();
            return false;
        }
        
        //By this point, the cell is a 1, so mark the cell as visited - I'll denote that as a "2"
        //The cell is a 1, so we will recursively call our solve function on it
        tempMaze[x][y][z] = "2";

        if (solve(tempMaze,x+1, y, z) || solve(tempMaze,x-1, y, z) || solve(tempMaze,x, y-1, z) || solve(tempMaze,x, y+1, z) || solve(tempMaze,x, y, z+1) || solve(tempMaze,x, y, z-1))
            return true;
        else
        {
            returnPath.pop_back();
            return false;
        }
    }
    
    
};
#endif /* Pathfinder_h */
