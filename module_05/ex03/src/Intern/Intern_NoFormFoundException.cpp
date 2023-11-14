#include "Intern.hpp"

Intern::NoFormFoundException::NoFormFoundException(void) {}

const char *Intern::NoFormFoundException::what(void) const throw()
{
	return "No form found\n";
}
