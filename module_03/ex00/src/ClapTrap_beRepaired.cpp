#include "ClapTrap.hpp"
#include <iostream>

void ClapTrap::beRepaired(unsigned int amount)
{
	if (health_pt > 0 && (energy_pt - static_cast<int>(amount)) >= 0)
	{
		std::cout << name << " repairs itself with " << amount << " points\n";
		health_pt += amount;
		energy_pt -= amount;
	}
	else if (health_pt == 0)
	{
		std::cout << name << " can't repairs itself with " << amount
				  << " points, because it's dead\n";
	}
	else
	{
		std::cout << name << " can't repairs itself with "
				  << amount << " points because of insufficient amount "
				  << "of energy points\n";
	}
}
