#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat #" << id << " default constructor called\n";
}

Cat::Cat(const Cat &obj) : Animal(obj.type)
{
	std::cout << "Cat #" << id << " copy constructor called\n";
}

Cat &Cat::operator=(const Cat &obj)
{
	std::cout << "Cat #" << id << " copy assignment operator called\n";
	this->type = obj.type;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat #" << id << " destructor called\n";
}
