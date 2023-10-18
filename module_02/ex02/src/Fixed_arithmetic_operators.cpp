#include "Fixed.hpp"
#include <cassert>

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(fpv + rhs.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(fpv - rhs.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	long int num_result = static_cast<long int>(fpv) *
						  static_cast<long int>(rhs.getRawBits());
	result.setRawBits(num_result >> fractional_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	assert(rhs.getRawBits() != 0 && "Zero Division");

	Fixed result;
	long int num_result = (static_cast<long int>(fpv) << fractional_bits) /
						  static_cast<long int>(rhs.getRawBits());
	result.setRawBits(num_result);
	return result;
}
