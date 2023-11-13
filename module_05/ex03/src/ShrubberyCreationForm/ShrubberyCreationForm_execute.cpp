#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	validateForExecution(executor);
}
