#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Brain *Cat::getBrain(void) const
{
	return brain;
}
Brain *Cat::getBrainAddress(void) const
{
	return this->brain;
}
