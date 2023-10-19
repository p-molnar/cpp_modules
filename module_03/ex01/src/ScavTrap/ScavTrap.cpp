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
	this->setDamagePt(0);
	std::cout << "String constructor of ScavTrap " << name << " called\n";
}

// ScavTrap::ScavTrap(const ScavTrap &obj)
// {
// 	std::cout << "Copy constructor of Scavtrap" << obj.getName() << " called\n";
// 	this->setName(obj.getName());
// 	this->setHealthPt(obj.getHealthPt());
// 	this->setEnergyPt(obj.getEnergyPt());
// 	this->setDamagePt(obj.getDamagePt());
// }
// const ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
// {
// 	std::cout << "Copy assignment constructor of ScavTrap" << obj.getName() << " called\n";
// 	this->setName(obj.getName());
// 	this->setHealthPt(obj.getHealthPt());
// 	this->setEnergyPt(obj.getEnergyPt());
// 	this->setDamagePt(obj.getDamagePt());
// 	return *this;
// }

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor of ScavTrap " << this->getName() << " called\n";
}

// std::ostream &operator<<(std::ostream &os, const ScavTrap &obj)
// {
// 	std::cout << "Name: " << obj.getName() << '\n';
// 	std::cout << "health_pt: " << obj.getHealthPt() << '\n';
// 	std::cout << "energy_pt: " << obj.getEnergyPt() << '\n';
// 	std::cout << "damage_pt: " << obj.getDamagePt() << '\n';
// 	return os;
// }
