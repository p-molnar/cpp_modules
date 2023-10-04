#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

void f(void)
{
	system("leaks violance");
}

int main(void)
{
	// atexit(f);
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
