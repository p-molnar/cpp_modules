#include "Fixed.hpp"

// overloading pre-decrement
Fixed Fixed::operator++(void)
{
	num += (1 << fractional_bits);
	return *this;
}

// overloading post-decrement
Fixed Fixed::operator++(int)
{
	Fixed tmp;
	tmp.setRawBits(num);
	num += (1 << fractional_bits);
	return tmp;
}
