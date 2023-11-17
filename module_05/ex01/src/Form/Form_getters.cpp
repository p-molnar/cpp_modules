#include "Form.hpp"

std::string Form::getName(void) const
{
	return name;
}

bool Form::getIsSigned(void) const
{
	return is_signed;
}

int Form::getSignGrade(void) const
{
	return grade_to_sign;
}

int Form::getExecuteGrade(void) const
{
	return grade_to_execute;
}
