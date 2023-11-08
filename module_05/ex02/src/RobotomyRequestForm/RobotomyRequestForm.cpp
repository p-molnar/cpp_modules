#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "Makes some drilling noises. Then, informs that "
			  << target << " has been robotomized successfully 50% of the"
			  << " time. Otherwise, informs that the robotomy failed.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
	: AForm(obj.getName(), obj.getSignGrade(), obj.getExecuteGrade())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	this->set_IsSigned(obj.getIsSigned());
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}
