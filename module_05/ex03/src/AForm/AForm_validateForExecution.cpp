#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

void AForm::validateForExecution(const Bureaucrat &executor) const
{
	if (!is_signed)
		throw AForm::FormNotSignedException();

	if (executor.getGrade() > grade_to_execute)
		throw AForm::GradeTooLowException();
}
