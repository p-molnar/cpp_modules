#include "ClapTrap.hpp"
#include <iostream>

void ClapTrap::beRepaired(unsigned int amount)
{
	if (health_pt == 0)
		return;

	if (static_cast<int>(amount) > energy_pt)
		amount = energy_pt;

	health_pt += amount;
	energy_pt -= amount;

	std::cout << "ClapTrap " << name
			  << " repairs itself with " << amount << " points\n";
	std::cout << "Current health point: " << health_pt << '\n';
	std::cout << "Current energy point: " << energy_pt << '\n';
}
