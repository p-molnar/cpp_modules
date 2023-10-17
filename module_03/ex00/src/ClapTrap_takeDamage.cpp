#include "ClapTrap.hpp"
#include <iostream>

void ClapTrap::takeDamage(unsigned int amount)
{
	if (health_pt == 0)
		return;

	amount = max(0, health_pt - amount);
	health_pt -= amount;
	std::cout << "ClapTrap " << name
			  << " takes damage, causing it to lose "
			  << amount << " of health points\n";
	std::cout << "Current health point: " << health_pt << '\n';
	std::cout << "Current energy point: " << energy_pt << '\n';
}
