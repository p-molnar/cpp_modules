#ifndef HUMANA_B
#define HUMANA_B

#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon *weapon;

public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon *weapon);
	void setWeapon(Weapon &weapon);
	void attack(void);
};

#endif
