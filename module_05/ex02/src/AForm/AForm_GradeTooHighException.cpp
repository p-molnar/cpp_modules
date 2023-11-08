#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException(void) {}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high\n";
}
