#ifndef INTERN__HPP
#define INTERN__HPP

#include "AForm.hpp"
#include <string>
#include <exception>

class Intern
{
public:
	Intern(void);
	Intern(std::string target);
	Intern(const Intern &obj);
	Intern &operator=(const Intern &obj);
	~Intern(void);

public:
	AForm *makeForm(std::string form_name, std::string target) const;
};

#endif
