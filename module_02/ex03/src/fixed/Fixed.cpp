#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

#define BITE_SIZE 8

// default constructor for obj declaration
Fixed::Fixed(void)
{
	fpv = 0;
	width = sizeof(fpv) * BITE_SIZE;
}

// default constructor for float
Fixed::Fixed(const float n)
{
	width = sizeof(fpv) * BITE_SIZE;
	fpv = Fixed::toFixedPoint(n, width, fractional_bits);
}

// default constructor for int
Fixed::Fixed(const int n)
{
	width = sizeof(fpv) * BITE_SIZE;
	fpv = toFixedPoint(n, width, fractional_bits);
}

// copy constructor
Fixed::Fixed(Fixed const &obj)
{
	fpv = obj.getRawBits();
	width = sizeof(fpv) * BITE_SIZE;
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &obj)
{
	fpv = obj.getRawBits();
	width = sizeof(fpv) * BITE_SIZE;
	return *this;
}

Fixed::~Fixed(void) {}

int Fixed::getWidth(void) const
{
	return width;
}

int Fixed::getFractionalBits(void) const
{
	return fractional_bits;
}

int Fixed::getRawBits(void) const
{
	return fpv;
}

void Fixed::setRawBits(const int n)
{
	fpv = n;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << std::setprecision(12) << obj.toFloat();
	return os;
}
