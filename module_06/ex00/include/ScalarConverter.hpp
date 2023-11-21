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
	const char *preprocess_number_arg(std::string n);

public:
	static void convert(const std::string n);
};

#endif
