#include "Fixed.hpp"

const Fixed Fixed::abs(const Fixed &obj)
{
	if (obj >= Fixed(0))
		return obj;

	Fixed result;
	int n = getTwosComplement(obj.getRawBits(), 32, 8);
	n += 1 << 8;
	result.setRawBits(n);
	return result;
}
