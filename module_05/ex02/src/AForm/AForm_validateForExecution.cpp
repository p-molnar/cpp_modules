#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

void AForm::validateForExecution(const Bureaucrat &executor) const
{
	if (is_signed != true && executor.getGrade() > grade_to_execute)
		throw AForm::GradeTooLowException();
}
