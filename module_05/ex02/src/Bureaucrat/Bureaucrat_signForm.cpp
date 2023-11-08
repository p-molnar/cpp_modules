#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

void Bureaucrat::signForm(AForm &form)
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
