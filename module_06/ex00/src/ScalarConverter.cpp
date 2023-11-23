#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void)obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter obj)
{
	(void)obj;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {}
