#include "WrongAnimal.hpp"
#include <string>

WrongAnimal::WrongAnimal(void) : type("") {}

WrongAnimal::WrongAnimal(std::string type) : type(type) {}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) : type(obj.type) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	this->type = obj.type;
	return *this;
}

WrongAnimal::~WrongAnimal(void) {}
