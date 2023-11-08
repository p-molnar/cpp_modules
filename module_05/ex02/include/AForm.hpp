#ifndef AFORM__HPP
#define AFORM__HPP

#include <string>
#include <exception>

class Bureaucrat;

class AForm
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
	bool is_signed;
	const int sign_grade;
	const int execute_grade;

public:
	AForm(void);
	AForm(std::string name,
		 const int sign_grade,
		 const int execute_grade);
	AForm(const AForm &obj);
	AForm &operator=(const AForm &obj);
	~AForm(void);

public:
	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;

public:
	void set_IsSigned(bool val);

public:
	void beSigned(const Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif
