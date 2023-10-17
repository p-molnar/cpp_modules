#include "Fixed.hpp"
#include <iostream>

// default constructor
Fixed::Fixed(void)
	: num(0)
{
	std::cout << "Default constructor called\n";
}

// copy constructor
Fixed::Fixed(Fixed &obj)
{
	std::cout << "Copy constructor called\n";
	num = obj.getRawBits();
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called\n";
	num = obj.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{

	std::cout << "getRawBits member function called\n";
	return num;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	num = raw;
}
