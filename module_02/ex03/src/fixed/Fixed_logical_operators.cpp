#include "Fixed.hpp"

bool Fixed::operator==(const Fixed &rhs) const
{
	return fixed_point_val == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return fixed_point_val != rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return fixed_point_val < rhs.getRawBits();
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return fixed_point_val > rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return fixed_point_val <= rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return fixed_point_val >= rhs.getRawBits();
}
