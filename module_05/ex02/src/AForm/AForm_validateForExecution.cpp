#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

void AForm::validateForExecution(const Bureaucrat &executor) const
{
	if (is_signed != true && executor.getGrade() > execute_grade)
		throw AForm::GradeTooLowException();
}
