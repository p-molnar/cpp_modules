#ifndef CLAPTRAP__H
#define CLAPTRAP__H

#include <string>

class ClapTrap
{
private:
	std::string name;
	int health_pt;
	int energy_pt;
	int damage_pt;

public:
	ClapTrap(std::string name);
	ClapTrap(void);
	ClapTrap(const ClapTrap &obj);
	const ClapTrap &operator=(const ClapTrap &obj);
	~ClapTrap(void);

public:
	const std::string &getName(void) const;
	int getHealthPt(void) const;
	int getEnergyPt(void) const;
	int getDamagePt(void) const;

public:
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &os, const ClapTrap &obj);

int min(int n1, int n2);
int max(int n1, int n2);

#endif
