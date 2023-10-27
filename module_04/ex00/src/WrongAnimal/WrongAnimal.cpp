#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal(void) : type("")
{
	id = c_id++;
	std::cout << "WrongAnimal #" << id << " default constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	id = c_id++;
	std::cout << "WrongAnimal #" << id << " string constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) : type(obj.type)
{
	std::cout << "WrongAnimal #" << id << " copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal #" << id << " copy assignment operator called\n";
	this->type = obj.type;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal #" << id << " destructor called\n";
}
