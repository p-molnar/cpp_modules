#ifndef BUREAUCRAT__HPP
#define BUREAUCRAT__HPP

#include <string>
#include <exception>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class AForm;

class Bureaucrat
{
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(void);
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(void);
		virtual const char *what(void) const throw();
	};

private:
	const std::string name;
	int grade;

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat &operator=(const Bureaucrat &obj);
	~Bureaucrat(void) throw();

public:
	const std::string &getName(void) const;
	int getGrade(void) const;

public:
	void increment(void);
	void decrement(void);

public:
	void signForm(AForm &form);
	void executeForm(const AForm &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
