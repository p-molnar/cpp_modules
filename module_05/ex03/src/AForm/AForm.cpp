#include "AForm.hpp"
#include <iostream>

#include "Bureaucrat.hpp"

AForm::AForm(void)
	: name("default"),
	  is_signed(false),
	  grade_to_sign(1),
	  grade_to_execute(1)
{
}

AForm::AForm(std::string name,
		   const int grade_to_sign,
		   const int grade_to_execute)
	: name(name),
	  is_signed(false),
	  grade_to_sign(grade_to_sign),
	  grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < HIGHEST_GRADE || grade_to_execute < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	else if (grade_to_sign > LOWEST_GRADE || grade_to_execute > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &obj)
	: name(obj.name),
	  is_signed(obj.is_signed),
	  grade_to_sign(obj.grade_to_sign),
	  grade_to_execute(obj.grade_to_execute)
{
	if (grade_to_sign < HIGHEST_GRADE || grade_to_execute < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	else if (grade_to_sign > LOWEST_GRADE || grade_to_execute > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(const AForm &obj)
{
	this->is_signed = obj.is_signed;
	return *this;
}

AForm::~AForm(void) {}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << "AForm\n";
	os << "- name: " << obj.getName() << '\n';
	os << "- is_signed: " << obj.getIsSigned() << '\n';
	os << "- grade_to_execute: " << obj.getExecuteGrade() << '\n';
	os << "- grade_to_sign: " << obj.getSignGrade() << '\n';
	return os;
}
