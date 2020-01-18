#pragma once
#include "FighterInterface.h"

using namespace std;

//Create a Fighter class that inheirits from the FI.h
/*		All fighters have the following attributes:
 *		Name - The fighter's name
 *		Hit Points - The amount of health the fighter has, with a specified maximum; reaching 0 is equivalent to losing
 *		Strength - Physical power, used to determine hit point regeneration
 *		Speed - Dexterity and physical movement, used to reduce damage when being attacked
 *		Magic - Magical prowess, used for some special abilities*/


class Fighter : public FighterInterface
{
public:
	
	Fighter();

	//these are the attributes that all fighters have in common
	Fighter(string name, int max_hp, int strength, int speed, int magic);

	//now declare th functions that we will use to obtain these stats
	
	string getName() const; //name
	int getMaximumHP() const; //Maximum Hit Points
	int getCurrentHP() const; //Current hit points
	int getStrength() const; //strength
	int getSpeed() const; //speed
	int getMagic() const; //magic

//Now we need to make a function that will determine damage in the game	

		 //*	getDamage() //use this name!!
		 //*
		 //*	Returns the amount of damage a fighter will deal.
		 //*
		 //*	Robot:
		 //*	This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.
		 //*
		 //*	Archer:
		 //*	This value is equal to the Archer's speed.
		 //*
		 //*	Cleric:
		 //*	This value is equal to the Cleric's magic.
	
//we will make this a virtual int because we will want it to be overriden in a derived class

	virtual int getDamage();
	

//Now, declare a function that will distribute damage during the game

	   	 //*	takeDamage(int)
		 //*
		 //*	Reduces the fighter's current hit points by an amount equal to the given 
		 //*	damage minus one fourth of the fighter's speed.  This method must reduce 
		 //*	the fighter's current hit points by at least one.  It is acceptable for 
		 //*	this method to give the fighter negative current hit points.
		 //*

//this will have a void return type because we don't want it to return anything, we just want it to send out the damage to the fighters
//also declare an int: damage that we'll pass in

	void takeDamage(int damage);

//Now we need to declare a function that will reset the current hit points to their maximum hit points

		/*
		 *	reset()
		 *
		 *	Restores a fighter's current hit points to its maximum hit points.
		 *
		 *	Robot:
		 *	Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
		 *	Also resets a Robot's bonus damage to 0.
		 *
		 *	Archer:
		 *	Also resets an Archer's current speed to its original value.
		 *
		 *	Cleric:
		 *	Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
		 */

//This shall also be virtual because it out children classes will override it ^ see how there are different ways each fighter deals with this? there ya go
	virtual void reset();

//Now we need a regenerate function

		/*
		 *	regenerate()
		 *
		 *	Increases the fighter's current hit points by an amount equal to one sixth of
		 *	the fighter's strength.  This method must increase the fighter's current hit 
		 *	points by at least one.  Do not allow the current hit points to exceed the 
		 *	maximum hit points.
		 *
		 *	Cleric:
		 *	Also increases a Cleric's current mana by an amount equal to one fifth of the 
		 *	Cleric's magic.  This method must increase the Cleric's current mana by at 
		 *	least one.  Do not allow the current mana to exceed the maximum mana.
		 */
		
//you guessed it, it's a virtual one too

	virtual void regenerate();


//NOW we need a use ability function!

	/*
		 *	useAbility()
		 *	
		 *	Attempts to perform a special ability based on the type of fighter.  The 
		 *	fighter will attempt to use this special ability just prior to attacking 
		 *	every turn.
		 *
		 *	Robot: Shockwave Punch
		 *	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
		 *	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
		 *	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
		 *		Examples:
		 *		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
		 *		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
		 *		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
		 *		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
		 *	Robot Note:
		 *	The bonus damage formula should be computed using double arithmetic, and only 
		 *	the final result should be cast into an integer.
		 *
		 *	Archer: Quickstep
		 *	Increases the Archer's speed by one point each time the ability is used.
		 *	This bonus lasts until the reset() method is used.
		 *	This ability always works; there is no maximum bonus speed.
		 *
		 *	Cleric: Healing Light
		 *	Increases the Cleric's current hit points by an amount equal to one third of its magic.
		 *	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
		 *	Will be used even if the Cleric's current HP is equal to their maximum HP.
		 *	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
		 *	Cleric Note:
		 *	This ability, when successful, must increase the Cleric's current hit points 
		 *	by at least one.  Do not allow the current hit points to exceed the maximum 
		 *	hit points.
		 *
		 *	Return true if the ability was used; false otherwise.
		 */
			
//yup yup, it's a virtual too. It's also a bool because we only want it to return true/false
	
	virtual bool useAbility();

//Now our protected data members
protected:
		string name;
		int max_hp;
		int current_hp;
		int strength;
		int speed;
		int magic;

};


