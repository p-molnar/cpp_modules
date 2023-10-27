#include "WrongCat.hpp"
#include "Animal.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat #" << id << " default constructor called\n";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj.type)
{
	std::cout << "WrongCat #" << id << " copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "WrongCat #" << id << " copy assignment operator called\n";
	this->type = obj.type;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat #" << id << " destructor called\n";
}
