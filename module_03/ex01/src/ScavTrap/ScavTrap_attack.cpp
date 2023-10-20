#include "ScavTrap.hpp"
#include <iostream>

void ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPt() <= 0)
	{
		std::cout << "ScavTrap " << this->getName()
				  << " can't attack because of insufficient amount"
				  << " of energy point(s)\n";
	}
	else if (this->getHealthPt() <= 0)
	{
		std::cout << "ScavTrap " << this->getName()
				  << " can't attack because it's dead\n";
	}
	else
	{
		std::cout << "ScavTrap " << this->getName()
				  << " attacks " << target << ", causing "
				  << this->getDamagePt() << " point(s) of damage!\n";
		this->setEnergyPt(this->getEnergyPt() - 1);
	}
}
