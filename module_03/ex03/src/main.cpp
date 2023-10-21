#include "DiamondTrap.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	DiamondTrap a("A");

	a.attack("B");
	a.printMembers();
	a.takeDamage(20);
	a.printMembers();
	a.beRepaired(15);
	a.printMembers();

	a.whoAmI();

	a.guardGate();

	a.highFivesGuys();

	return EXIT_SUCCESS;
}
