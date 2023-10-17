#include "Fixed.hpp"

bool Fixed::operator==(const Fixed &rhs) const
{
	return num == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return num != rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return num < rhs.getRawBits();
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return num > rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return num <= rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return num >= rhs.getRawBits();
}
