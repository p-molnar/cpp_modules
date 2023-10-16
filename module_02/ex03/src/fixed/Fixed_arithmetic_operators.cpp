#include "Fixed.hpp"

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(fixed_point_val + rhs.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(
		fixed_point_val + getTwosComplement(rhs.getRawBits(),
											rhs.getWidth(),
											rhs.getFractionalBits()));
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	int64_t num_result = fixed_point_val * rhs.getRawBits();
	result.setRawBits(num_result >> fractional_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	assert(rhs.getRawBits() != 0 && "Zero Division");

	Fixed result;
	int64_t num_result = (fixed_point_val << fractional_bits) / rhs.getRawBits();
	result.setRawBits(num_result);
	return result;
}
