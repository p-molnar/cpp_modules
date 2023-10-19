#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	ClapTrap obj_clap("A");
	ScavTrap obj_scav("B");

	obj_scav.attack("C");
	std::cout << obj_scav << '\n';
	obj_scav.takeDamage(8);
	std::cout << obj_scav << '\n';

	obj_scav.beRepaired(3);
	std::cout << obj_scav << '\n';

	obj_scav.takeDamage(8);
	std::cout << obj_scav << '\n';
	obj_scav.attack("C");
	std::cout << obj_scav << '\n';
	obj_scav.beRepaired(2);
	std::cout << obj_scav << '\n';
	return EXIT_SUCCESS;
}
