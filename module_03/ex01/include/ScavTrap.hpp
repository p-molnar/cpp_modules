#ifndef SCAVTRAP__H
#define SCAVTRAP__H

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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

// std::ostream &operator<<(std::ostream &os, const ScavTrap &obj);

#endif
