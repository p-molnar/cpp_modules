#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

AForm *Intern::makeForm(std::string form_name, std::string target) const
{
	const int form_size = 3;
	AForm *return_form = NULL;
	AForm *forms[3] = {
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target),
		new ShrubberyCreationForm(target)};

	for (int i = 0; i < form_size; i++)
	{
		if (forms[i]->getName() == form_name)
			return_form = forms[i];
		else
			delete forms[i];
	}

	if (return_form)
		std::cout << "Intern creates " << form_name << '\n';
	else
		throw Intern::NoFormFoundException();

	return return_form;
}
