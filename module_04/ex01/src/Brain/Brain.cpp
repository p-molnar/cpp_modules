#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) { std::cout << "Brain default constructor called\n"; }

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructor called\n";
	memcpy(ideas, obj.ideas, SIZE);
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout << "Brain copy assignment operator called\n";
	memcpy(ideas, obj.ideas, SIZE);
	return *this;
}

Brain::~Brain(void) { std::cout << "Brain destructor called\n"; }
