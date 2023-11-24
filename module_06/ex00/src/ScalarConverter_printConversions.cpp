#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

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
	if (number == number &&
		(number >= std::numeric_limits<int>::min() &&
		 number <= std::numeric_limits<int>::max()))
	{
		std::cout << static_cast<int>(number);
	}
	else
		std::cout << "impossible";
	std::cout << '\n';
}

void ScalarConverter::printFloatConversion(double number, int precision)
{
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "float: ";
	if (std::isinf(number) || std::isnan(number) ||
		(number >= -std::numeric_limits<float>::max() &&
		 number <= std::numeric_limits<float>::max()))
	{
		std::cout << static_cast<float>(number) << 'f';
	}
	else
		std::cout << "impossible";
	std::cout << '\n';
}

void ScalarConverter::printDoubleConversion(double number, int precision)
{
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "double: ";
	if (std::isinf(number) || std::isnan(number) ||
		(number >= -std::numeric_limits<double>::max() &&
		 number <= std::numeric_limits<double>::max()))
	{
		std::cout << number;
	}
	else
		std::cout << "impossible";
	std::cout << '\n';
}
