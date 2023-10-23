#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(void)
{
	std::cout << "Default constructor of FragTrap called\n";
	this->setHealthPt(frag_health_pt);
	this->setEnergyPt(frag_energy_pt);
	this->setDamagePt(frag_damage_pt);
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "String constructor of FragTrap "
			  << this->getName() << " called\n";

	this->setHealthPt(100);
	this->setEnergyPt(100);
	this->setDamagePt(30);
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap()
{
	std::cout << "Copy constructor of FragTrap "
			  << this->getName() << " called\n";

	this->setName(obj.getName());
	this->setHealthPt(obj.getHealthPt());
	this->setEnergyPt(obj.getEnergyPt());
	this->setDamagePt(obj.getDamagePt());
}

const FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "Copy assignment constructor of FragTrap "
			  << this->getName() << " called\n";

	this->setName(obj.getName());
	this->setHealthPt(obj.getHealthPt());
	this->setEnergyPt(obj.getEnergyPt());
	this->setDamagePt(obj.getDamagePt());
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor of FragTrap " << this->getName() << " called\n";
}
