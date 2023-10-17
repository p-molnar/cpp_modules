#include "Fixed.hpp"

bool Fixed::operator==(const Fixed &rhs) const
{
	return fpv == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return fpv != rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return fpv < rhs.getRawBits();
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return fpv > rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return fpv <= rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return fpv >= rhs.getRawBits();
}
