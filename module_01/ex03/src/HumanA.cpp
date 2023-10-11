#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: name(name), weapon(weapon) {}

void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << '\n';
}
