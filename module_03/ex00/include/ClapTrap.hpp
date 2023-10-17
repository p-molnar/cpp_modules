#ifndef CLAPTRAP__H
#define CLAPTRAP__H

#include <string>

class ClapTrap
{
private:
	std::string name;
	int energy_pt;
	int health_pt;
	int damage_pt;

public:
	ClapTrap(std::string);
	ClapTrap(void);
	ClapTrap(const ClapTrap &obj);
	const ClapTrap &operator=(const ClapTrap &obj);
	~ClapTrap(void);

public:
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

int min(int n1, int n2);
int max(int n1, int n2);

#endif
