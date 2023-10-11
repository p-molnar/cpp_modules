#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: name(name), weapon(NULL) {}

HumanB::HumanB(std::string name, Weapon *weapon)
	: name(name), weapon(weapon) {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack(void)
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType();
	else
		std::cout << name << " doesn't have a weapon to attack with";
	std::cout << std::endl;
}
