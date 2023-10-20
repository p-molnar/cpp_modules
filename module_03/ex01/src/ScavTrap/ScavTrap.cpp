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
	std::cout << "String constructor of ScavTrap "
			  << this->getName() << " called\n";

	this->setHealthPt(100);
	this->setEnergyPt(50);
	this->setDamagePt(20);
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	std::cout << "Copy constructor of ScavTrap "
			  << this->getName() << " called\n";

	this->setName(obj.getName());
	this->setHealthPt(obj.getHealthPt());
	this->setEnergyPt(obj.getEnergyPt());
	this->setDamagePt(obj.getDamagePt());
}

const ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "Copy assignment constructor of ScavTrap "
			  << this->getName() << " called\n";

	this->setName(obj.getName());
	this->setHealthPt(obj.getHealthPt());
	this->setEnergyPt(obj.getEnergyPt());
	this->setDamagePt(obj.getDamagePt());
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor of ScavTrap " << this->getName() << " called\n";
}
