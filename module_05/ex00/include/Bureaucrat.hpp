#ifndef BUREAUCRAT__HPP
#define BUREAUCRAT__HPP

#include <string>
#include "GradeTooLowException.hpp"
#include "GradeTooHighException.hpp"
#include <exception>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat : public GradeTooHighException, GradeTooLowException
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat &operator=(const Bureaucrat &obj);
	virtual ~Bureaucrat(void) throw();

public:
	const std::string &getName(void) const;
	int getGrade(void) const;

public:
	void increment(void);
	void decrement(void);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
