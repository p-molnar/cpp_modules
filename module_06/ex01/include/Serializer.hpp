#ifndef SERIALIZE__HPP
#define SERIALIZE__HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer &);
	Serializer &operator=(const Serializer &obj);
	~Serializer(void);

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
