#include "Form.hpp"

Form::GradeTooLowException::GradeTooLowException(void) {}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low\n";
}
