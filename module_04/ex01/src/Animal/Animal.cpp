#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal(void) : type("")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal string constructor called\n";
}

Animal::Animal(const Animal &obj) : type(obj.type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << "Animal copy assingment operator called\n";
	this->type = obj.type;
	return *this;
}

Animal::~Animal(void) {}
