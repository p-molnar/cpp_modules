#ifndef ROBOTOMYREQUESTFORM__HPP
#define ROBOTOMYREQUESTFORM__HPP

#include "AForm.hpp"
#include <string>
#include <exception>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &obj);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
	~RobotomyRequestForm(void);
};

#endif
