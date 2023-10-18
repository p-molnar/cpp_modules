#include "ClapTrap.hpp"
#include <iostream>

void ClapTrap::takeDamage(unsigned int amount)
{
	amount = min(amount, health_pt);
	if (health_pt > 0)
	{
		std::cout << "ClapTrap " << name
				  << " takes damage, and loses "
				  << amount << " of health points\n";
		health_pt -= min(health_pt, amount);
	}
	else
	{
		std::cout << "ClapTrap " << name
				  << " is dead, can't take any damages\n";
	}
}
