#include "ClapTrap.hpp"
#include <iostream>

void ClapTrap::takeDamage(unsigned int amount)
{
	amount = min(amount, health_pt);
	if (health_pt > 0)
	{
		std::cout << name << " takes damage, and loses "
				  << amount << " of health point(s)\n";
		health_pt -= min(health_pt, amount);
	}
	else
	{
		std::cout << name << " is dead, can't take any damages\n";
	}
}
