#include "DiamondTrap.hpp"
#include <iostream>

void DiamondTrap::whoAmI(void)
{
	std::cout << "name: " << name << '\n';
	std::cout << "ClapTrap name: " << ClapTrap::getName() << '\n';
}
