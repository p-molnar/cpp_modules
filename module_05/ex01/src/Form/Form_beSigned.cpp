#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::beSigned(const Bureaucrat &obj)
{
	int bureaucrat_grade = obj.getGrade();
	if (bureaucrat_grade > sign_grade)
		throw Form::GradeTooLowException();
}
