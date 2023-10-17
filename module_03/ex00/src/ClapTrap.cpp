#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "String constructor called\n";
	this->name = name;
	this->health_pt = 10;
	this->energy_pt = 10;
	this->damage_pt = 1;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy constructor called\n";
	this->name = obj.name;
	this->health_pt = obj.health_pt;
	this->energy_pt = obj.energy_pt;
	this->damage_pt = obj.damage_pt;
}
const ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Copy assignment called\n";
	this->name = obj.name;
	this->health_pt = obj.health_pt;
	this->energy_pt = obj.energy_pt;
	this->damage_pt = obj.damage_pt;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called\n";
}
