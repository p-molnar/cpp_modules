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
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter &operator=(const ScalarConverter obj);
	~ScalarConverter(void);

private:
	static void isValidNumericalFormat(std::string num_arg);
	static void printCharConversion(double number);
	static void printIntConversion(double number);
	static void printFloatConversion(double number, int precision);
	static void printDoubleConversion(double number, int precision);

public:
	static void convert(const std::string n);
};

#endif
