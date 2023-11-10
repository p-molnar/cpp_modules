#ifndef SHRUBBERYCREATIONFORM__HPP
#define SHRUBBERYCREATIONFORM__HPP

#include "AForm.hpp"
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &obj);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
	~ShrubberyCreationForm(void);

public:
	void execute(const Bureaucrat &executor) const;
};

#endif
