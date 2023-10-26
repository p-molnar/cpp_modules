#include "Brain.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

Brain::Brain(void)
{
	std::cout << "Brain default constructor called\n";
	for (int i = 0; i < 5; i++)
		ideas[0] += (rand() % 25) + 65;
}

Brain::Brain(const Brain *obj)
{
	std::cout << "Brain* copy constructor called\n";
	for (int i = 0; i < BRAIN_CAPACITY; i++)
		ideas[i] = obj->ideas[i];
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructor called\n";
	for (int i = 0; i < BRAIN_CAPACITY; i++)
		ideas[i] = obj.ideas[i];
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout << "Brain copy assignment operator called\n";
	if (this != &obj)
	{
		for (int i = 0; i < BRAIN_CAPACITY; i++)
			ideas[i] = obj.ideas[i];
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called\n";
}
