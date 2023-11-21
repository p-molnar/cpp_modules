#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::InvalidNumericalFormatException::InvalidNumericalFormatException(void)
{
}

const char *ScalarConverter::InvalidNumericalFormatException::what(void) const throw()
{
	return "invalid numerical format";
}
