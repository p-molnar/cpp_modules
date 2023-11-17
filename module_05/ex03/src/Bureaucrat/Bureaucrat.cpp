#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name), grade(grade)
{
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
	: name(obj.name), grade(obj.grade)
{
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	grade = obj.grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void) throw() {}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", "
	   << "bureaucrat grade " << obj.getGrade();
	return osperator << (std::ostream & os, const Bureaucrat &obj)
	{
		os << obj.getName() << ", "
		   << "bureaucrat grade " << obj.getGrade();
		return os;
	};
}
