#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

void ScalarConverter::printCharConversion(double number)
{
	std::cout << "char: ";

	// check for float and double nan & -/+inf
	if ((number == number) && isascii(number))
	{
		if (isprint(number))
			std::cout << static_cast<char>(number);
		else
			std::cout << "non displayable";
	}
	else
		std::cout << "impossible";
	std::cout << '\n';
}

void ScalarConverter::printIntConversion(double number)
{
	std::cout << "int: ";

	// check for float and double nan & -/+inf
	if (number == number)
		std::cout << static_cast<int>(number);
	else
		std::cout << "impossible";
	std::cout << '\n';
}

void ScalarConverter::printFloatConversion(double number, int precision)
{
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "float: ";

	std::cout << static_cast<float>(number) << 'f';
	std::cout << '\n';
}

void ScalarConverter::printDoubleConversion(double number, int precision)
{
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "double: ";

	std::cout << number << '\n';
}
