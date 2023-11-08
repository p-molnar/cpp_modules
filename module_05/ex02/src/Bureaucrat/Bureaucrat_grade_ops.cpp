#include "Bureaucrat.hpp"

void Bureaucrat::increment(void)
{
	if (grade - 1 < HIGHEST_GRADE)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrement(void)
{
	if (grade + 1 > LOWEST_GRADE)
		throw GradeTooLowException();
	grade++;
}
