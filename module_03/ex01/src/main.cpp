#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	ScavTrap a("A");
	std::cout << a << '\n';

	a.attack("B");
	std::cout << a << '\n';
	a.takeDamage(20);
	std::cout << a << '\n';
	a.beRepaired(10);
	std::cout << a << '\n';
	a.guardGate();
	std::cout << a << '\n';
	return EXIT_SUCCESS;
}
