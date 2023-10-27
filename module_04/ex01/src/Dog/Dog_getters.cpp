#include "Dog.hpp"
#include <iostream>

const std::string &Dog::getBrainIdea(unsigned int i) const
{
	return brain->getIdea(i);
}

Brain *Dog::getBrainAddress(void) const
{
	return this->brain;
}
