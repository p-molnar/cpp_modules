#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor of ClapTrap called\n";
}

ClapTrap::ClapTrap(std::string name)
	: name(name), health_pt(10), energy_pt(10), damage_pt(1)
{
	std::cout << "String constructor of " << name << " called\n";
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy constructor of " << name << " called\n";
	name = obj.name;
	health_pt = obj.health_pt;
	energy_pt = obj.energy_pt;
	damage_pt = obj.damage_pt;
}
const ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Copy assignment constructor of " << name << " called\n";
	name = obj.name;
	health_pt = obj.health_pt;
	energy_pt = obj.energy_pt;
	damage_pt = obj.damage_pt;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor of " << name << " called\n";
}

std::ostream &operator<<(std::ostream &os, const ClapTrap &obj)
{
	std::cout << "Name: " << obj.getName() << '\n';
	std::cout << "health_pt: " << obj.getHealthPt() << '\n';
	std::cout << "energy_pt: " << obj.getEnergyPt() << '\n';
	std::cout << "damage_pt: " << obj.getDamagePt() << '\n';
	return os;
}
