#ifndef SHRUBBERYCREATIONFORM__HPP
#define SHRUBBERYCREATIONFORM__HPP

#include "AForm.hpp"
#include <string>
#include <exception>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &obj);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
	~ShrubberyCreationForm(void);
};

#endif
