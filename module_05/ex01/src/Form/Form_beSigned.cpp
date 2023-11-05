#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > sign_grade)
		throw Form::GradeTooLowException();
	this->is_signed = true;
}
