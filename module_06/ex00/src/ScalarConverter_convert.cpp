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

		bool is_double = num_arg.find('.') != std::string::npos;
		bool is_float = is_double && num_arg.find('f') != std::string::npos;
		int decimal_len = num_arg.length() - num_arg.find('.') - 1;
		int precision = is_double ? decimal_len - is_float : 1;

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
