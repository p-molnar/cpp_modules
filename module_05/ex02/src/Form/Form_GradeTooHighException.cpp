#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(void) {}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high\n";
}
