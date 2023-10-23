#ifndef DIAMONDTRAP__H
#define DIAMONDTRAP__H

#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;

public:
	DiamondTrap(std::string name);
	DiamondTrap(void);
	DiamondTrap(const DiamondTrap &obj);
	const DiamondTrap &operator=(const DiamondTrap &obj);
	~DiamondTrap(void);

public:
	using ScavTrap::attack;
	void whoAmI(void);
};

#endif
