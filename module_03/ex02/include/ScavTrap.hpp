#ifndef SCAVTRAP__H
#define SCAVTRAP__H

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
protected:
	static const int scav_health_pt = 100;
	static const int scav_energy_pt = 50;
	static const int scav_damage_pt = 20;

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
