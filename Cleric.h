#ifndef CLERIC_H
#define CLERIC_H
#include <iostream>
#include "Fighter.h"
#include "FighterInterface.h"


using namespace std;

//Declare the Cleric Class!

class Cleric : public Fighter
{

public:
	Cleric(string name, int strength, int hp, int speed, int magic);


    
    
//Now we need those other functions, get damage, reset, use ability, and regenerate

	
//here's the specifics for the Cleric damage stuff

		 //*	Returns the amount of damage a fighter will deal.
		 //*
		 //*	Cleric:
		 //*	This value is equal to the Cleric's magic.

	int getDamage();


//Specifics for Cleric Reset:
		 //*	Restores a fighter's current hit points to its maximum hit points.
		 //*
		 //*	Cleric:
		 //*	Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).


	void reset();


//Specifics for Cleric Use Ability:

		 //*	Attempts to perform a special ability based on the type of fighter.  The 
		 //*	fighter will attempt to use this special ability just prior to attacking 
		 //*	every turn.

		 //*	Cleric: Healing Light
		 //*	Increases the Cleric's current hit points by an amount equal to one third of its magic.
		 //*	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
		 //*	Will be used even if the Cleric's current HP is equal to their maximum HP.
		 //*	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
		 //*	Cleric Note:
		 //*	This ability, when successful, must increase the Cleric's current hit points 
		 //*	by at least one.  Do not allow the current hit points to exceed the maximum 
		 //*	hit points.
		 //*
		 //*	Return true if the ability was used; false otherwise.

	bool useAbility();


//Specifics for Cleric Regenerate:

		 //*	Increases the fighter's current hit points by an amount equal to one sixth of
		 //*	the fighter's strength.  This method must increase the fighter's current hit 
		 //*	points by at least one.  Do not allow the current hit points to exceed the 
		 //*	maximum hit points.
		 //*
		 //*	Cleric:
		 //*	Also increases a Cleric's current mana by an amount equal to one fifth of the 
		 //*	Cleric's magic.  This method must increase the Cleric's current mana by at 
		 //*	least one.  Do not allow the current mana to exceed the maximum mana.

	void regenerate();

private:
	int max_mana;
	int current_mana;

};
#endif
