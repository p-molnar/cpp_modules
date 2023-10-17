#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

#define BITE_SIZE 8

// default constructor for obj declaration
Fixed::Fixed(void)
{
	width = sizeof(num) * BITE_SIZE;
	num = 0;
}

// default constructor for float
Fixed::Fixed(const float n)
{
	width = sizeof(num) * BITE_SIZE;
	num = Fixed::toFixedPoint(n, width, fractional_bits);
}

// default constructor for int
Fixed::Fixed(const int n)
{
	width = sizeof(num) * BITE_SIZE;
	num = toFixedPoint(n, width, fractional_bits);
}

// copy constructor
Fixed::Fixed(Fixed const &obj)
{
	num = obj.num;
	width = sizeof(num) * BITE_SIZE;
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &obj)
{
	num = obj.num;
	width = sizeof(num) * BITE_SIZE;
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
	return num;
}

void Fixed::setRawBits(const int n)
{
	num = n;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << std::setprecision(12) << obj.toFloat();
	return os;
}

void print_bin(int n)
{
	int j = 1;
	for (int i = 31; i >= 0; i--)
	{
		std::cout << ((n >> i) & 1);
		if (j > 0 && !(j % 8))
			std::cout << "  ";
		j++;
	}
	std::cout << '\n';
}
