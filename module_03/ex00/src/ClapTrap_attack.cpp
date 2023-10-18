#include "ClapTrap.hpp"
#include <string>
#include <iostream>

void ClapTrap::attack(const std::string &target)
{
	if (energy_pt > 0)
	{
		std::cout << "ClapTrap " << name
				  << " attacks " << target << ", causing "
				  << damage_pt << " points of damage!\n";
		energy_pt--;
	}
}
