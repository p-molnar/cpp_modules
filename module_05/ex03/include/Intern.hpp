#ifndef INTERN__HPP
#define INTERN__HPP

#include "AForm.hpp"
#include <string>
#include <exception>

class Intern
{
	class NoFormFoundException : public std::exception
	{
	public:
		NoFormFoundException(void);
		virtual const char *what(void) const throw();
	};

public:
	Intern(void);
	Intern(std::string target);
	Intern(const Intern &obj);
	Intern &operator=(const Intern &obj);
	~Intern(void);

private:
	static AForm *getRobotomyRequestForm(std::string target);
	static AForm *getPresidentialPardonForm(std::string target);
	static AForm *getShrubberyCreationForm(std::string target);

public:
	AForm *makeForm(std::string form_name, std::string target) const;
};

#endif
