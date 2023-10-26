#include "Dog.hpp"
#include <iostream>

std::string Dog::getBrain(void) const
{
	return brain->ideas[0];
}

Brain *Dog::getBrainAddress(void) const
{
	return this->brain;
}
