#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

void Cat::deepCopy(const Cat &obj)
{
	type = obj.type;

	delete brain;

	if (obj.brain)
		brain = new Brain(obj.brain);
	else
		brain = NULL;
}
