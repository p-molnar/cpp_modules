#ifndef SCALARCONVERTER__HPP
#define SCALARCONVERTER__HPP

#include <string>
#include <exception>

class ScalarConverter
{
	class InvalidNumericalFormatException : public std::exception
	{
	public:
		InvalidNumericalFormatException(void);
		virtual const char *what(void) const throw();
	};

private:
	ScalarConverter(){};

private:
	void static isValidNumericalFormat(std::string num_arg);
	void static printCharConversion(double number);
	void static printIntConversion(double number);
	void static printFloatConversion(double number, int precision);
	void static printDoubleConversion(double number, int precision);

public:
	static void convert(const std::string n);
};

#endif
