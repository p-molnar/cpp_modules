#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > grade_to_sign)
		throw AForm::GradeTooLowException();
	this->is_signed = true;
}
