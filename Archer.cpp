#include "Archer.h"
#include "Fighter.h"
#include "FighterInterface.h"

Archer::Archer(string name, int hp, int strength, int speed, int magic):Fighter(name, hp, strength, speed, magic)
{
	original_speed = speed;
}

int Archer:: getDamage()
{
	return speed;
}

void Archer::reset()
{
	current_hp = max_hp;
	speed = original_speed;
}

bool Archer::useAbility()
{
	speed+= 1;
	return true;
}

void Archer:: regenerate()
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
