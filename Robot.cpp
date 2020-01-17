#include "Robot.h"
#include <cmath>

Robot::Robot(string name, int hp, int strength, int speed, int magic) : Fighter(name, hp, strength, speed, magic)
{
	bonus =0;

	maximum_energy = magic *2;
	current_energy = maximum_energy;
}

int Robot::getDamage()
{
	int damage = strength + bonus;

	bonus = 0;

	return damage;
}

void Robot::reset()
{
	current_hp = max_hp;
	current_energy = maximum_energy;
	bonus = 0;
}

bool Robot::useAbility()
{
	if (current_energy >= ROBOT_ABILITY_COST)
	{
		bonus = (strength * pow((current_energy/maximum_energy),4.0));

		current_energy -= ROBOT_ABILITY_COST;
		return true;
	}

	else
	{
		bonus = 0;
		return false;
	}

}

void Robot::regenerate()
{
	if(current_hp < max_hp)
	{
		int hp_increase = (strength/6);
		
		if (hp_increase > 0)
		{
			current_hp += hp_increase;
		}

		if (hp_increase <= 0)
		{
			current_hp++;
		}

		if(current_hp > max_hp)
		{
			current_hp = max_hp;
		}
	}
}
