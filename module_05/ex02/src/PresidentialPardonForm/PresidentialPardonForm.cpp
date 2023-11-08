#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "Informs that "
			  << target
			  << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj.getName(), obj.getSignGrade(), obj.getExecuteGrade())
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	this->set_IsSigned(obj.getIsSigned());
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}
