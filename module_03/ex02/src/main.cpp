#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	FragTrap a("A");

	std::cout << a << '\n';
	a.takeDamage(100);
	a.attack("B");
	a.highFivesGuys();
	std::cout << a << '\n';

	return EXIT_SUCCESS;
}
