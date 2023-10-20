#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(void)
{
	std::cout << "Default constructor of ScavTrap called\n";
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "String constructor of ScavTrap " << name << " called\n";
	this->setHealthPt(100);
	this->setEnergyPt(50);
	this->setDamagePt(20);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor of ScavTrap " << this->getName() << " called\n";
}
