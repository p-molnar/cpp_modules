#ifndef GRADETOOLOWEXCEPTION__HPP
#define GRADETOOLOWEXCEPTION__HPP

#include <exception>

class GradeTooLowException : public std::exception
{
public:
	GradeTooLowException(void){};
	virtual const char *what(void) const throw() { return "Grade too low\n"; }
};

#endif
