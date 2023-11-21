#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

bool is_valid_numerical_format(std::string s)
{
	int len = s.length();
	int i = 0;

	if (s == "-inff" || s == "+inff" || s == "nanf")
		return true;

	while (i < len)
	{
		if (isdigit(s[i]))
			i++;
		if (s[i] == '.')
			i++;
		if (isdigit(s[i]))
			i++;
		if (s[i] == 'f')
			i++;
	}
	if (i == (len - 1))
		return true;
	return false;
}

const char *ScalarConverter::preprocess_number_arg(std::string n)
{
	if (!is_valid_numerical_format(n))
		throw ScalarConverter::InvalidNumericalFormatException();
	return "a";
}

void ScalarConverter::convert(const std::string n)
{
	try
	{
		// const char *number = preprocess_number_arg(n);
		std::string a = n;
		const char *nu = a.c_str();
		float num = std::atof(nu);
		std::cout << "char: " << static_cast<char>(num) << "\n";
		std::cout << "int: " << static_cast<int>(num) << "\n";
		std::cout << "float: " << static_cast<float>(num) << "\n";
		std::cout << "double: " << static_cast<double>(num) << "\n";
	}
	catch (std::exception &e)
	{
		e.what();
	}
}
