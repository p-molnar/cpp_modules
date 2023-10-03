#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string arg_name)
{
	name = arg_name;
}

Zombie::~Zombie(void)
{
	std::cout << "destructing: " << name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
