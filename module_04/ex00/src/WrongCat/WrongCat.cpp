#include "WrongCat.hpp"
#include "Animal.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj.type) {}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	this->type = obj.type;
	return *this;
}

WrongCat::~WrongCat(void) {}
