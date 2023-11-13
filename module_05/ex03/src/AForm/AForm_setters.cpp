#include "AForm.hpp"

std::string AForm::getName(void) const
{
	return name;
}

bool AForm::getIsSigned(void) const
{
	return is_signed;
}

int AForm::getSignGrade(void) const
{
	return sign_grade;
}

int AForm::getExecuteGrade(void) const
{
	return execute_grade;
}
