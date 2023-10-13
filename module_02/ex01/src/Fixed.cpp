#include "Fixed.hpp"
#include <iostream>

#define BIT_SIZE 8

// default constructor for float
Fixed::Fixed(const float n)
{
	fixed_point_val = Fixed::toFixedPoint(n,
										  sizeof(fixed_point_val) * BIT_SIZE,
										  fractional_bits);
}

// default constructor for int
Fixed::Fixed(const int n)
{
	fixed_point_val = toFixedPoint(n,
								   sizeof(fixed_point_val) * BIT_SIZE,
								   fractional_bits);
}

// float Fixed::operator<<(int fixed_point_val)
// {
// 	(void)fixed_point_val;
// }

// copy constructor
Fixed::Fixed(Fixed &num)
	: fixed_point_val(num.fixed_point_val)
{
	std::cout << "Copy constructor called\n";
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &fixed)
{
	fixed_point_val = fixed.fixed_point_val;
	std::cout << "Copy assignment operator called\n";
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{

	std::cout << "getRawBits member function called\n";
	return fixed_point_val;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	fixed_point_val = raw;
}
