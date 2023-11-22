#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

void ScalarConverter::convert(std::string num_arg)
{
	try
	{
		isValidNumericalFormat(num_arg);

		const char *str = num_arg.c_str();
		char *str_end = (char *)str + num_arg.length();

		double number = std::strtod(str, &str_end);

		int precision = num_arg.find('.') == std::string::npos
							? 1
							: num_arg.length() - num_arg.find('.') - 1;

		printCharConversion(number);
		printIntConversion(number);
		printFloatConversion(number, precision);
		printDoubleConversion(number, precision);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
}
