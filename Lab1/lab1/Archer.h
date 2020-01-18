#include <iostream>
#include "Fighter.h"
#include "FighterInterface.h"
#pragma once
using namespace std;

//Write that archer class
//verrrrrry similar to cleric class, just different formulas

class Archer : public Fighter
{
public:
	Archer(string name, int strength, int hp, int speed, int magic);

// declare get damage, reset, use ability, regenerate

//Archer damage specifics:

		 //*	Returns the amount of damage a fighter will deal.
		 //*	Archer:
		 //*	This value is equal to the Archer's speed.
	
	int getDamage();

//Archer reset specifics:

		//Restores a fighter's current hit points to its maximum hit points.
		//Archer:
		//Also resets an Archer's current speed to its original value.
		
	void reset();

//Archer use ability specifics:

		 //*	Attempts to perform a special ability based on the type of fighter.  The 
		 //*	fighter will attempt to use this special ability just prior to attacking 
		 //*	every turn.
		 //*	Archer: Quickstep
		 //*	Increases the Archer's speed by one point each time the ability is used.
		 //*	This bonus lasts until the reset() method is used.
		 //*	This ability always works; there is no maximum bonus speed.

	bool useAbility();

	void regenerate();

private:
	int original_speed;

};
