#include "Dog.hpp"
#include "Brain.hpp"

void Dog::deepCopy(const Dog &obj)
{
	type = obj.type;

	delete brain;
	if (brain)
		brain = new Brain(obj.brain);
	else
		brain = NULL;
}
