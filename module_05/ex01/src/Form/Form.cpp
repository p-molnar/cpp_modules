#include "Form.hpp"
#include <iostream>

#include "Bureaucrat.hpp"

Form::Form(void)
	: name("default"),
	  is_signed(false),
	  grade_to_sign(1),
	  grade_to_execute(1)
{
}

Form::Form(std::string name,
		   const int grade_to_sign,
		   const int grade_to_execute)
	: name(name),
	  is_signed(false),
	  grade_to_sign(grade_to_sign),
	  grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < HIGHEST_GRADE || grade_to_execute < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > LOWEST_GRADE || grade_to_execute > LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &obj)
	: name(obj.name),
	  is_signed(obj.is_signed),
	  grade_to_sign(obj.grade_to_sign),
	  grade_to_execute(obj.grade_to_execute)
{
	if (grade_to_sign < HIGHEST_GRADE || grade_to_execute < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > LOWEST_GRADE || grade_to_execute > LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &obj)
{
	this->is_signed = obj.is_signed;
	return *this;
}

Form::~Form(void) {}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "Form\n";
	os << "- name: " << obj.getName() << '\n';
	os << "- is_signed: " << obj.getIsSigned() << '\n';
	os << "- grade_to_execute: " << obj.getExecuteGrade() << '\n';
	os << "- grade_to_sign: " << obj.getSignGrade() << '\n';
	return os;
}
