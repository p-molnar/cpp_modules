#ifndef FRAGTRAP__H
#define FRAGTRAP__H

#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
protected:
	static const int frag_health_pt = 100;
	static const int frag_energy_pt = 100;
	static const int frag_damage_pt = 30;

public:
	FragTrap(std::string name);
	FragTrap(void);
	FragTrap(const FragTrap &obj);
	const FragTrap &operator=(const FragTrap &obj);
	~FragTrap(void);

public:
	void highFivesGuys(void);
};

#endif
