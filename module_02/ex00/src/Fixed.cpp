#include "Fixed.hpp"
#include <iostream>

// default constructor
Fixed::Fixed(void)
	: fpv(0)
{
	std::cout << "Default constructor called\n";
}

// copy constructor
Fixed::Fixed(Fixed &obj)
{
	std::cout << "Copy constructor called\n";
	fpv = obj.getRawBits();
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called\n";
	fpv = obj.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{

	std::cout << "getRawBits member function called\n";
	return fpv;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	fpv = raw;
}
