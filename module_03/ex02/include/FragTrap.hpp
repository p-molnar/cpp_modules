#ifndef FRAGTRAP__H
#define FRAGTRAP__H

#include <string>
#include "ScavTrap.hpp"

class FragTrap : public ScavTrap
{
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
