#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat"), brain(new Brain)
{
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat &obj) : Animal(obj.type)
{
	std::cout << "Cat copy constructor called\n";

	deepCopy(obj);
}

Cat &Cat::operator=(const Cat &obj)
{
	std::cout << "Cat copy assignment operator called\n";

	deepCopy(obj);
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called\n";

	delete brain;
}

void Cat::deepCopy(const Cat &obj)
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
