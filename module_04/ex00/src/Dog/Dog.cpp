#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {}

Dog::Dog(const Dog &obj) : Animal(obj.type) {}

Dog &Dog::operator=(const Dog &obj)
{
	this->type = obj.type;
	return *this;
}

Dog::~Dog(void) {}
