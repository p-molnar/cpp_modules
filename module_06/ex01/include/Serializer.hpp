#ifndef SERIALIZE__HPP
#define SERIALIZE__HPP

#include "Data.hpp"

class Serializer
{
private:
	Serializer(){};

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
