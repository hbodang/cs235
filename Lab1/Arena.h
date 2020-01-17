#pragma once
#include <iostream>
#include <sstream>

#include "Archer.h"
#include "Fighter.h"
#include "Robot.h"
#include "Cleric.h"
#include "ArenaInterface.h"
//#include "FighterInterface.h"


class Arena : public ArenaInterface
{

public:
	Arena();

	//virtual ~ArenaInterface(){}
	//ArenaInterface(){}

		
	//virtual bool addFighter(string info) = 0;
	//bool addFighter(string info);
    bool addFighter(string info);
		
	//virtual bool removeFighter(string name) = 0;
	//bool removeFighter(string name);
    bool removeFighter(string name);
		
	//virtual FighterInterface* getFighter(string name) = 0;
	//FighterInterface* getFighter(string name);
    FighterInterface* getFighter(string name);
    
    
	//virtual int getSize() = 0;
	int getSize() const;


private:
	
	//make a vector that points to the fighter interface...for arena?
	//vector <FighterInterface*> players;
    vector <FighterInterface*> players;
};
