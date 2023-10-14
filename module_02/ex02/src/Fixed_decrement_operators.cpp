#include "Fixed.hpp"

// overloading pre-decrement
Fixed Fixed::operator--(void)
{
	fixed_point_val -= (1 << fractional_bits);
	return *this;
}

// overloading post-decrement
Fixed Fixed::operator--(int)
{
	Fixed tmp;
	tmp.setRawBits(fixed_point_val);
	fixed_point_val -= (1 << fractional_bits);
	return tmp;
}
