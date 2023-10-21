#ifndef SCAVTRAP__H
#define SCAVTRAP__H

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

public:
	ScavTrap(std::string name);
	ScavTrap(void);
	ScavTrap(const ScavTrap &obj);
	const ScavTrap &operator=(const ScavTrap &obj);
	~ScavTrap(void);

public:
	void attack(const std::string &target);
	void guardGate(void);
};

#endif
