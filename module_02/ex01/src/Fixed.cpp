#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

#define BITE_SIZE 8

// default constructor for obj declaration
Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	fpv = 0;
	width = sizeof(fpv) * BITE_SIZE;
}

// default constructor for float
Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called\n";
	width = sizeof(fpv) * BITE_SIZE;
	fpv = Fixed::toFixedPoint(n, width, fractional_bits);
}

// default constructor for int
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	width = sizeof(fpv) * BITE_SIZE;
	fpv = toFixedPoint(n, width, fractional_bits);
}

// copy constructor
Fixed::Fixed(Fixed const &obj)
{
	std::cout << "Copy constructor called\n";
	fpv = obj.getRawBits();
	width = sizeof(fpv) * BITE_SIZE;
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called\n";
	fpv = obj.getRawBits();
	width = sizeof(fpv) * BITE_SIZE;
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

void Fixed::setRawBits(const int n)
{
	std::cout << "setRawBits member function called\n";
	fpv = n;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
}
