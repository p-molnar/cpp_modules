#include "Intern.hpp"
#include <iostream>

AForm *Intern::makeForm(std::string form_name, std::string target) const
{
	const int form_size = 3;
	AForm *(*fn_ptr[form_size])(std::string) =
		{
			getRobotomyRequestForm,
			getPresidentialPardonForm,
			getShrubberyCreationForm};

	std::string fn_names[form_size] =
		{
			"robotomy request",
			"presidential pardon",
			"shrubbery creation"};

	AForm *form = NULL;

	for (int i = 0; i < form_size; i++)
	{
		if (fn_names[i] == form_name)
		{
			form = fn_ptr[i](target);
		}
	}

	if (form)
	{
		std::cout << "Intern creates " << form_name << '\n';
	}
	else
		throw Intern::NoFormFoundException();

	return form;
}
