#include "Arena.h"
#include "Archer.h"
#include "Cleric.h"
#include "Fighter.h"
#include "Robot.h"
using namespace std;

//call addfighter method from the arena.h file
Arena::Arena()
{
	vector<FighterInterface*> players;
}


//Time to add a fighter!
bool Arena::addFighter(std::string info)
{
	stringstream ss(info);
    std::string name, type;
	int hp, strength, speed, magic;

	if (ss >> name >> type >> hp >> strength >> speed >> magic)
	{
		if (ss.eof())
		{
			//this is so that we don't have negative values for fighter attributes
			if (hp<=0 || strength <=0 || speed <=0 || magic <= 0)
			{
				return false;
			}

			//see if fighter name is already in the list
			for (int i = 0; i <players.size(); i++)
			{
				if(name == players[i]->getName())
				{
					return false;
				}
			}


			if (type == "R")
			{
				//add a new Robot fighter

                Robot* R = new Robot(name, hp, strength, speed, magic);
				players.push_back(R);

			}
			else if (type == "A")
			{
				//add a new Archer
				Archer* A = new Archer(name, hp, strength, speed, magic);
				players.push_back(A);
			}

			else if (type == "C")
			{
				//add a new cleric
				Cleric* C = new Cleric(name, hp, strength, speed, magic);
				players.push_back(C);
			}

			else
			{
				//If it's not a Robot, Archer, or Cleric, it's wrong!
				return false;
			}
			return true;
		}	
		else return false;
		
	}
	return false;
}
//Now it's time to Remove a fighter!
bool Arena::removeFighter(string name)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (name == players[i]->getName())
		{

			players.erase(players.begin() +i);
			return true;
		}
	}
	return false;
}

//gives the address of the player whose name is equal to the given name.  Returns NULL if no fighter is found with the given name.
FighterInterface* Arena::getFighter(string name)
{
	for (int i=0; i < players.size(); i++)
	{
		if (name == players[i]->getName())
		{
			return players[i];
		}
	}
	return NULL;
}
int Arena::getSize() const
{
	return players.size();
}
//now go make the Fighter class for your Arena!
