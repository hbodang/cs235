#include "Fighter.h"

//This is our fighter class! yay
Fighter::Fighter(string N, int max_HP, int STH, int SPD, int MAG)
{
	//this is what all of these data members are called in this doc
	name = N;
	max_hp = max_HP;
	strength = STH;
	speed = SPD;
	magic = MAG;

}

//Now let's make those functions we declared earlier
// These ones:
	//string getName(); //name
	//int getMaximumHP(); //Maximum Hit Points
	//int getCurrentHP(); //Current hit points
	//int getStrength(); //strength
	//int getSpeed(); //speed
	//int getMagic(); //magic


string Fighter::getName() const
{
	return name;
}

int Fighter::getMaximumHP() const
{
	return max_hp;
}

int Fighter::getCurrentHP() const
{
	return current_hp;
}

int Fighter::getStrength() const
{
	return strength;
}

int Fighter::getSpeed() const
{
	return speed;
}

int Fighter::getMagic() const
{
	return magic;
}


//Now we write our Get Damage function

int Fighter::getDamage()
{
	return 0;
}


//Now we write our Take Damage function

void Fighter::takeDamage(int damage)
{
	//use the logic given in the FI.h to determine the equation to calculate the damage that is given to the fighter
	int damage_taken = damage - (speed/4);
	if (damage_taken > 1)
	{
		current_hp -= (damage_taken);
	}
	if (damage_taken <= 1)
	{
		current_hp--;
	}
}

//Write the reset function!

void Fighter::reset()
{
	current_hp = max_hp;
}

void Fighter::regenerate()
{
	
}

bool Fighter::useAbility()
{
	return true;
}

//now go make those Cleric, Archer, and Robot classes
