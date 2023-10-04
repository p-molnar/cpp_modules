#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type)
	: type(type) {}

std::string Weapon::getType(void)
{
	return type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
