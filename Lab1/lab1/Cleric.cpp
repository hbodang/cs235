#include "Cleric.h"

Cleric::Cleric(string name, int hp, int strength, int speed, int magic):Fighter(name, hp, strength, speed, magic)
{
	max_mana = magic * 5;
}

int Cleric::getDamage()
{
	return magic;
}

void Cleric::reset()
{
	current_hp = max_hp;
	current_mana = max_mana;
}

bool Cleric::useAbility()
{

	if (current_mana >= CLERIC_ABILITY_COST)
	{
		int hp_increase = (magic/3);
		if (hp_increase >= 0)
		{
			current_hp += hp_increase;
		}
		else if (hp_increase <= 0)
		{
			current_hp++;
		}
		if (current_hp > max_hp)
		{
			current_hp = max_hp;
		}

			current_mana -= CLERIC_ABILITY_COST;
			return true;

	}

	else
	{
		return false;
	}
}


void Cleric::regenerate()
{
	if (current_hp < max_hp)
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
		if (current_hp > max_hp)
		{
			current_hp = max_hp;
		}
	}

	if (current_mana < max_mana)
	{
		int mana_increase = current_mana + (magic/5);
		if (mana_increase > 0)
		{
			current_mana = mana_increase;
		}
		if (mana_increase < 0)
		{
			current_mana += 1;
		}
		if (mana_increase > max_mana)
		{
			current_mana = max_mana;
		}
	}
}
