#include "ScavTrap.hpp"
#include <iostream>

void ScavTrap::guardGate(void)
{
	if (this->getHealthPt() > 0)
		std::cout << "ScavTrap " << this->getName()
				  << " is in gate keeper mode\n";
	else
		std::cout << "ScavTrap " << this->getName()
				  << " can't be in gate keeper mode, because it's dead\n";
}
