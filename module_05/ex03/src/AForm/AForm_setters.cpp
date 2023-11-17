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
	return grade_to_sign;
}

int AForm::getExecuteGrade(void) const
{
	return grade_to_execute;
}
