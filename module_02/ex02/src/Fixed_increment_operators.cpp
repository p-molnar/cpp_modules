#include "Fixed.hpp"

// overloading pre-decrement
Fixed Fixed::operator++(void)
{
	fpv += (1 << fractional_bits);
	return *this;
}

// overloading post-decrement
Fixed Fixed::operator++(int)
{
	Fixed tmp;
	tmp.setRawBits(fpv);
	fpv += (1 << fractional_bits);
	return tmp;
}
