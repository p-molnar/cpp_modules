#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void Bureaucrat::signForm(const Form &obj)
{
	if (obj.getIsSigned)
		std::cout << name << " signed " << obj.getName() << '\n';
	else
		std::cout << name << " couldn't signe " << obj.getName()
				  << " because of insufficient grade level\n";
}