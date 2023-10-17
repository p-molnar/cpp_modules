#include "ClapTrap.hpp"
#include <string>
#include <iostream>

void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << name
			  << " attacks " << target << ", causing "
			  << damage_pt << " points of damage !\n";
	energy_pt--;
	std::cout << "Current health point: " << health_pt << '\n';
	std::cout << "Current energy point: " << energy_pt << '\n';
}
