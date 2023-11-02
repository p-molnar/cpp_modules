#include "Bureaucrat.hpp"

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low\n";
}
