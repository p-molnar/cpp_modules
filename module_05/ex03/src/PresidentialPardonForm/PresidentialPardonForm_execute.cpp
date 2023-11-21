#include "PresidentialPardonForm.hpp"
#include <iostream>

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{

	validateForExecution(executor);
	std::cout << this->getTarget()
			  << " has been pardoned by Zaphod Beeblebrox.\n";
}
