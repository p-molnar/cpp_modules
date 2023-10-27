#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog #" << id << " default constructor called\n";
}

Dog::Dog(const Dog &obj) : Animal(obj.type)
{
	std::cout << "Dog #" << id << " copy constructor called\n";
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << "Dog #" << id << " copy assignment operator called\n";
	this->type = obj.type;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog #" << id << " destructor called\n";
}
