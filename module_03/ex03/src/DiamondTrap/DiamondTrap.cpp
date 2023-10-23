#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(void)
{
	std::cout << "Default constructor of DiamondTrap called\n";
	this->setHealthPt(FragTrap::frag_health_pt);
	this->setEnergyPt(ScavTrap::scav_energy_pt);
	this->setDamagePt(FragTrap::frag_damage_pt);
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
	this->setHealthPt(FragTrap::frag_health_pt);
	this->setEnergyPt(ScavTrap::scav_energy_pt);
	this->setDamagePt(FragTrap::frag_damage_pt);
	std::cout << "String constructor of DiamondTrap " << name << " called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
	: ClapTrap(),
	  ScavTrap(),
	  FragTrap()
{
	std::cout << "Copy constructor of DiamondTrap "
			  << this->getName() << " called\n";

	this->setName(obj.getName());
	this->setHealthPt(FragTrap::getHealthPt());
	this->setEnergyPt(ScavTrap::getEnergyPt());
	this->setDamagePt(FragTrap::getDamagePt());
}

const DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout << "Copy assignment constructor of DiamondTrap "
			  << this->getName() << " called\n";

	this->setName(obj.getName());
	this->setHealthPt(obj.getHealthPt());
	this->setEnergyPt(obj.getEnergyPt());
	this->setDamagePt(obj.getDamagePt());
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor of DiamondTrap " << name << " called\n";
}
