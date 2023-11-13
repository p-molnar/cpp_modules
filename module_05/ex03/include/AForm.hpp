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

	// instantiation / destroying related member functions
public:
	AForm(void);
	AForm(std::string name,
		  const int sign_grade,
		  const int execute_grade);
	AForm(const AForm &obj);
	AForm &operator=(const AForm &obj);
	virtual ~AForm(void);

	// getters
public:
	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;

	// setters
public:
	void set_IsSigned(bool val);

public:
	void beSigned(const Bureaucrat &obj);

protected:
	void validateForExecution(const Bureaucrat &executor) const;

public:
	virtual void execute(const Bureaucrat &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif
