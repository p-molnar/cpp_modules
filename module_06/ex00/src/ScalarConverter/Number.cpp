#include "Number.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

Number::Number(void) : flags(0) {}

Number::Number(const Number &obj)
{
	flags = obj.flags;
	type = obj.type;
}

Number &Number::operator=(const Number &obj)
{
	flags = obj.flags;
	type = obj.type;
	return (*this);
}

Number::~Number(void) {}
