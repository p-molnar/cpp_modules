#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

void ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPt() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing "
				  << this->getDamagePt() << " point(s) of damage!\n";
		this->setEnergyPt(this->getEnergyPt() - 1);
	}
	else
	{
		std::cout << "ScavTrap " << this->getName()
				  << " can't attack because of insufficient amount"
				  << " of energy point(s)\n";
	}
}
