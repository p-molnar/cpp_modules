#include "ClapTrap.hpp"
#include <string>
#include <iostream>

void ClapTrap::attack(const std::string &target)
{
	if (energy_pt <= 0)
	{
		std::cout << "ClapTrap " << name
				  << " can't attack because of insufficient amount"
				  << " of energy point(s)\n";
	}
	if (health_pt <= 0)
	{
		std::cout << "ClapTrap " << name
				  << " can't attack because it's dead\n";
	}
	else
	{
		std::cout << "ClapTrap " << name
				  << " attacks " << target << ", causing "
				  << damage_pt << " point(s) of damage!\n";
		energy_pt--;
	}
}
