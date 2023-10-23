#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(void) : Animal("Cat") {}

Cat::Cat(const Cat &obj) : Animal(obj.type) {}

Cat &Cat::operator=(const Cat &obj)
{
	this->type = obj.type;
	return *this;
}

Cat::~Cat(void) {}
