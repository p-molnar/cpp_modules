#ifndef GRADETOOHIGHEXCEPTION__HPP
#define GRADETOOHIGHEXCEPTION__HPP

#include <exception>

class GradeTooHighException : public std::exception
{
public:
	GradeTooHighException(){};
	virtual const char *what() const throw() { return "Grade too high\n"; }
};

#endif
