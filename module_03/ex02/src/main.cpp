#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	FragTrap a("A");

	std::cout << a << '\n';
	a.takeDamage(80);
	std::cout << a << '\n';
	a.attack("B");
	std::cout << a << '\n';
	a.highFivesGuys();
	std::cout << a << '\n';
	a.attack("B");
	std::cout << a << '\n';
	a.beRepaired(30);
	std::cout << a << '\n';
	a.attack("B");
	a.beRepaired(67);
	std::cout << a << '\n';
	a.beRepaired(67);
	std::cout << a << '\n';
	a.beRepaired(1);
	std::cout << a << '\n';
	a.takeDamage(200);
	std::cout << a << '\n';
	a.highFivesGuys();
	std::cout << a << '\n';

	return EXIT_SUCCESS;
}
