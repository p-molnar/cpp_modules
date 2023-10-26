#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog #" << id << " default constructor called\n ";

	brain = new Brain;
}

Dog::Dog(const Dog &obj) : Animal(obj.type)
{
	std::cout << "Dog copy constructor called\n";
	std::cout << "Dog #" << id << " copy constructor called\n ";

	deepCopy(obj);
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << "Dog #" << id << " copy assignment operator called\n";
	deepCopy(obj);
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog #" << id << " destructor called\n";

	delete brain;
}
