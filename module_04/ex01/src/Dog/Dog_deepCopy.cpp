#include "Dog.hpp"
#include "Brain.hpp"

void Dog::deepCopy(const Dog &obj)
{
	type = obj.type;

	delete brain;

	if (obj.brain)
	{
		brain = new Brain;
		memcpy(brain, obj.brain, sizeof(Brain));
	}
	else
		brain = NULL;
}
