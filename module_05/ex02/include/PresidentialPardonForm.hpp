#ifndef PRESIDENTIALPARDONFORM__HPP
#define PRESIDENTIALPARDONFORM__HPP

#include "AForm.hpp"
#include <string>
#include <exception>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &obj);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
	~PresidentialPardonForm(void);
};

#endif
