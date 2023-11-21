#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	validateForExecution(executor);
	srand(time(NULL));

	std::cout << "Drilling noises Grrr\n";
	std::cout << this->getTarget();

	if (rand() % 2)
		std::cout << " has been robotomized\n";
	else
		std::cout << " has failed\n";
}
