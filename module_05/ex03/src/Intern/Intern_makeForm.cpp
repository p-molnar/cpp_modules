#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

AForm *Intern::makeForm(std::string form_name, std::string target) const
{
	const int form_size = 3;
	AForm *forms[form_size] =
		{
			new ShrubberyCreationForm(target),
			new PresidentialPardonForm(target),
			new RobotomyRequestForm(target)};

	AForm *result = nullptr;

	for (int i = 0; i < form_size; i++)
	{
		if (form_name == forms[i]->getName())
			result = forms[i];
		delete forms[i];
	}

	return result;
}
