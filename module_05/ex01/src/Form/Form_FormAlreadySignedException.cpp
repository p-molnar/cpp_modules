#include "Form.hpp"

Form::FormAlreadySignedException::FormAlreadySignedException(void) {}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed\n";
}
