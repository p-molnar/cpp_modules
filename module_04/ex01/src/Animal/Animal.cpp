#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal(void) : type("")
{
	id = c_id++;
	std::cout << "Animal #" << id << " default constructor called\n";
}

Animal::Animal(std::string type) : type(type)
{
	id = c_id++;
	std::cout << "Animal #" << id << " string constructor called\n";
}

Animal::Animal(const Animal &obj) : type(obj.type)
{
	std::cout << "Animal #" << id << " copy constructor called\n";
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << "Animal #" << id << " copy assignment operator called\n";
	this->type = obj.type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal #" << id << " destructor called\n";
}
