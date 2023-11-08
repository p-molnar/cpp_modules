#include "AForm.hpp"
#include <iostream>

#include "Bureaucrat.hpp"

AForm::AForm(void)
	: name("default"),
	  is_signed(false),
	  sign_grade(1),
	  execute_grade(1)
{
}

AForm::AForm(std::string name,
		   const int sign_grade,
		   const int execute_grade)
	: name(name),
	  is_signed(false),
	  sign_grade(sign_grade),
	  execute_grade(execute_grade)
{
	if (sign_grade < HIGHEST_GRADE || execute_grade < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	else if (sign_grade > LOWEST_GRADE || execute_grade > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &obj)
	: name(obj.name),
	  is_signed(obj.is_signed),
	  sign_grade(obj.sign_grade),
	  execute_grade(obj.execute_grade)
{
	if (sign_grade < HIGHEST_GRADE || execute_grade < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	else if (sign_grade > LOWEST_GRADE || execute_grade > LOWEST_GRADE)
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
	os << "- execute_grade: " << obj.getExecuteGrade() << '\n';
	os << "- sign_grade: " << obj.getSignGrade() << '\n';
	return os;
}
