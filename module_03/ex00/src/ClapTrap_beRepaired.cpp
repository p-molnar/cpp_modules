#include "ClapTrap.hpp"
#include <iostream>

void ClapTrap::beRepaired(unsigned int amount)
{
	if (health_pt > 0 && (energy_pt - static_cast<int>(amount)) >= 0)
	{
		std::cout << "ClapTrap " << name << " repairs itself with "
				  << amount << " point(s)\n";
		health_pt += amount;
		energy_pt -= amount;
	}
	else if (health_pt == 0)
	{
		std::cout << "ClapTrap " << name << " can't repair itself with "
				  << amount << " point(s), because it's dead\n";
	}
	else
	{
		std::cout << "ClapTrap " << name << " can't repair itself with "
				  << amount << " point(s) because of insufficient amount "
				  << "of energy point(s)\n";
	}
}
