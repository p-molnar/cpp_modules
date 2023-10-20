#include "FragTrap.hpp"
#include <iostream>

void FragTrap::highFivesGuys(void)
{
	if (this->getHealthPt() > 0)
		std::cout << "Give me high five! ( ^o^)ノ\n";
	else
		std::cout << "FragTrap " << this->getName()
				  << " can't ask for high five, because it's dead\n";
}
