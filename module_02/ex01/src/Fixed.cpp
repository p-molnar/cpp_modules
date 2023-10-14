#include "Fixed.hpp"
#include <iostream>

#define BIT_SIZE 8

// default constructor for obj declaration
Fixed::Fixed(void)
{
	std::cout << "default constructor called\n";
}

// default constructor for float
Fixed::Fixed(const float n)
{
	std::cout << "float constructor called\n";
	width = sizeof(fixed_point_val) * BIT_SIZE;
	fixed_point_val = Fixed::toFixedPoint(n, width, fractional_bits);
}

// default constructor for int
Fixed::Fixed(const int n)
{
	std::cout << "int constructor called\n";
	width = sizeof(fixed_point_val) * BIT_SIZE;
	fixed_point_val = toFixedPoint(n, width, fractional_bits);
}

// copy constructor
Fixed::Fixed(const Fixed &num)
{
	std::cout << "Copy constructor called\n";
	fixed_point_val = num.fixed_point_val;
	width = sizeof(fixed_point_val) * BIT_SIZE;
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called\n";
	fixed_point_val = fixed.fixed_point_val;
	width = sizeof(fixed_point_val) * BIT_SIZE;
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

void print_bin(int bin)
{
	int j = 1;
	for (int i = 31; i >= 0; i--)
	{
		std::cout << ((bin >> i) & 1);
		if (j > 0 && !(j % 8))
			std::cout << "  ";
		j++;
	}
	std::cout << '\n';
}
