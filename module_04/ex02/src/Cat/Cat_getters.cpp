#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

const std::string &Cat::getBrainIdea(unsigned int i) const
{
	return brain->getIdea(i);
}
Brain *Cat::getBrainAddress(void) const
{
	return this->brain;
}
