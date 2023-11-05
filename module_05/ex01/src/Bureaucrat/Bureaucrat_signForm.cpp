#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void Bureaucrat::signForm(const Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn't sign " << form.getName()
				  << " because " << e.what();
	}
}
