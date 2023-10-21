#include "DiamondTrap.hpp"
#include <iostream>

void DiamondTrap::printMembers(void)
{
	std::cout << "name: " << name << '\n';
	std::cout << "health_pt: " << health_pt << '\n';
	std::cout << "energy_pt: " << energy_pt << '\n';
	std::cout << "damage_pt: " << damage_pt << '\n';
}
