#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name) : name(name) {}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
