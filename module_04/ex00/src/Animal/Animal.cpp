#include "Animal.hpp"
#include <string>

Animal::Animal(void) : type("") {}

Animal::Animal(std::string type) : type(type) {}

Animal::Animal(const Animal &obj) : type(obj.type) {}

Animal &Animal::operator=(const Animal &obj)
{
	this->type = obj.type;
	return *this;
}

Animal::~Animal(void) {}
