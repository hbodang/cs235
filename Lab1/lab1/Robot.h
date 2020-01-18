#include <iostream>
#pragma once
#include "Fighter.h"
#include "FighterInterface.h"

class Robot : public Fighter //this is saying that our class robot, inherits from the public class fighter
{
public:
    Robot(string name, int strength, int hp, int speed, int magic);

//Do Robot damage, reset, useability, and regenerate

//Robot damage specifics:

		 //*	Returns the amount of damage a fighter will deal.
		 //*
		 //*	Robot:
		 //*	This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.

	int getDamage();

//Robot reset specifics:

		 //*	Restores a fighter's current hit points to its maximum hit points.
		 //*
		 //*	Robot:
		 //*	Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
		 //*	Also resets a Robot's bonus damage to 0.

	void reset();

//Robot use ability specifics:

		 //*	Attempts to perform a special ability based on the type of fighter.  The 
		 //*	fighter will attempt to use this special ability just prior to attacking 
		 //*	every turn.
		 //*
		 //*	Robot: Shockwave Punch
		 //*	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
		 //*	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
		 //*	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
		 //*		Examples:
		 //*		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
		 //*		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
		 //*		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
		 //*		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
		 //*	Robot Note:
		 //*	The bonus damage formula should be computed using double arithmetic, and only 
		 //*	the final result should be cast into an integer.

	bool useAbility();

	void regenerate();

private:
	double bonus;
	double maximum_energy;
	double current_energy;

};
