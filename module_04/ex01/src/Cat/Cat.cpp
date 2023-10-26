#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat #" << id << " default constructor called\n";
	brain = new Brain;
}

Cat::Cat(const Cat &obj) : Animal(obj.type)
{
	std::cout << "Cat #" << id << " copy constructor called\n";

	deepCopy(obj);
}

Cat &Cat::operator=(const Cat &obj)
{
	std::cout << "Cat #" << id << " copy assignment operator called\n";

	deepCopy(obj);
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat #" << id << " destructor called\n";

	delete brain;
}
