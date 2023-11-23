#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &obj) { (void)obj; }

Serializer &Serializer::operator=(const Serializer &obj)
{
	(void)obj;
	return *this;
}

Serializer::~Serializer(void) {}
