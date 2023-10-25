#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog"), brain(new Brain)
{
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog &obj) : Animal(obj.type)
{
	std::cout << "Dog copy constructor called\n";

	deepCopy(obj);
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << "Dog copy assignment operator called\n";

	deepCopy(obj);
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called\n";

	delete brain;
}
