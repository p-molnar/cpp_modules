#include "PresidentialPardonForm.hpp"
#include <iostream>

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	validateForExecution(executor);
}
