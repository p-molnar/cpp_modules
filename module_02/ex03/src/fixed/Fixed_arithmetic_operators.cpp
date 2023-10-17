#include "Fixed.hpp"

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(fpv + rhs.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(
		fpv + getTwosComplement(rhs.getRawBits(),
								rhs.getWidth(),
								rhs.getFractionalBits()));
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	int64_t num_result = fpv * rhs.getRawBits();
	result.setRawBits(num_result >> fractional_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	assert(rhs.getRawBits() != 0 && "Zero Division");

	Fixed result;
	int64_t num_result = (fpv << fractional_bits) / rhs.getRawBits();
	result.setRawBits(num_result);
	return result;
}
