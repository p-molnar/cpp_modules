#include "DiamondTrap.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	DiamondTrap a("A");
	// ScavTrap b("B");
	a.attack("B");
	a.whoAmI();
	// a.printMembers();

	return EXIT_SUCCESS;
}
