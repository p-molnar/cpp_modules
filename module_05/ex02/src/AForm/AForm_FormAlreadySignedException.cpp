#include "AForm.hpp"

AForm::FormAlreadySignedException::FormAlreadySignedException(void) {}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed\n";
}
