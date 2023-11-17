#ifndef FORM__HPP
#define FORM__HPP

#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	class FormAlreadySignedException : public std::exception
	{
	public:
		FormAlreadySignedException(void);
		virtual const char *what() const throw();
	};

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
	const int grade_to_sign;
	const int grade_to_execute;

public:
	Form(void);
	Form(std::string name,
		 const int grade_to_sign,
		 const int grade_to_execute);
	Form(const Form &obj);
	Form &operator=(const Form &obj);
	~Form(void);

public:
	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;

public:
	void beSigned(const Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
