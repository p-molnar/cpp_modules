#include "RobotomyRequestForm.hpp"
#include <iostream>

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	validateForExecution(executor);
}
