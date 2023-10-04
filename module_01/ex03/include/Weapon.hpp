#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
	std::string type;

public:
	Weapon(std::string type);
	std::string getType(void);
	void setType(std::string type);
};

#endif
