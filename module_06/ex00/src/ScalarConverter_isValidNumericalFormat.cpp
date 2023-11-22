#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

bool ScalarConverter::isValidNumericalFormat(std::string num_arg)
{
	int i = 0;
	std::string double_sci = "nan-inf+inf";
	std::string float_sci = "nanf-inff+inff";

	if (double_sci.find(num_arg) != std::string::npos ||
		float_sci.find(num_arg) != std::string::npos)
		return true;

	if (num_arg[i] == '-' || num_arg[i] == '+')
		i++;
	while (isdigit(num_arg[i]))
		i++;
	if (num_arg[i] == '.')
		i++;
	while (isdigit(num_arg[i]))
		i++;
	if (num_arg[i] == 'f')
		i++;
	if (i == static_cast<int>(num_arg.length()))
		return true;
	return false;
}
