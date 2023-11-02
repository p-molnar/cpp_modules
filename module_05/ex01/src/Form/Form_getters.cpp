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
	return sign_grade;
}

int Form::getExecuteGrade(void) const
{
	return execute_grade;
}
