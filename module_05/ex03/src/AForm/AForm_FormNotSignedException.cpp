#include "AForm.hpp"

AForm::FormNotSignedException::FormNotSignedException(void) {}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed\n";
}
