#include "Fixed.hpp"

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
	return (obj1 < obj2) ? obj1 : obj2;
}

Fixed const &Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 < obj2) ? obj1 : obj2;
}
