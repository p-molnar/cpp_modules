#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high\n";
}
