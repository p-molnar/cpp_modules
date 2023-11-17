#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > grade_to_sign)
		throw Form::GradeTooLowException();
	this->is_signed = true;
}
