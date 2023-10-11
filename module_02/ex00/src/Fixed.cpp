#include "Fixed.hpp"
#include <iostream>

// default constructor
Fixed::Fixed(void)
	: fixed_point_val(0)
{
	std::cout << "Default constructor called\n";
}

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
