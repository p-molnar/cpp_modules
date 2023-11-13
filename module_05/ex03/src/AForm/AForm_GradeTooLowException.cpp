#include "AForm.hpp"

AForm::GradeTooLowException::GradeTooLowException(void) {}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low\n";
}
