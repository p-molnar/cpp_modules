#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <unistd.h>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137, "default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
	: AForm(obj.getName(),
			obj.getSignGrade(),
			obj.getExecuteGrade(),
			obj.getTarget())
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	this->set_IsSigned(obj.getIsSigned());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
