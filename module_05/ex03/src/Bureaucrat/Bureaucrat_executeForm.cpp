#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << name << " can't execute "
				  << form.getName() << " because "
				  << e.what();
	}
}
