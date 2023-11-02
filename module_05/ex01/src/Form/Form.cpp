#include "Form.hpp"
#include <iostream>

#include "Bureaucrat.hpp"

Form::Form(void)
	: name("default"),
	  sign_grade(-1),
	  execute_grade(-1)
{
}

Form::Form(std::string name,
		   const int sign_grade,
		   const int execute_grade)
	: name(name),
	  is_signed(false),
	  sign_grade(sign_grade),
	  execute_grade(execute_grade)
{
	if (sign_grade < HIGHEST_GRADE || execute_grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	else if (sign_grade > LOWEST_GRADE || execute_grade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &obj)
	: name(obj.name),
	  is_signed(obj.is_signed),
	  sign_grade(obj.sign_grade),
	  execute_grade(obj.execute_grade)
{
	if (sign_grade < HIGHEST_GRADE || execute_grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	else if (sign_grade > LOWEST_GRADE || execute_grade > LOWEST_GRADE)
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
	os << "- execute_grade: " << obj.getExecuteGrade() << '\n';
	os << "- sign_grade: " << obj.getSignGrade() << '\n';
	return os;
}
