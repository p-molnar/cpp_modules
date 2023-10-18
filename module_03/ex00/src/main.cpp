#include "ClapTrap.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	ClapTrap t("A");

	t.attack("B");
	std::cout << t << '\n';
	t.takeDamage(5);
	std::cout << t << '\n';
	t.beRepaired(5);
	std::cout << t << '\n';
	t.takeDamage(2);
	std::cout << t << '\n';
	t.beRepaired(10);
	std::cout << t << '\n';
	t.beRepaired(10);
	std::cout << t << '\n';

	return EXIT_SUCCESS;
}
