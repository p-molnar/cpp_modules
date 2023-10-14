#include "Fixed.hpp"
#include <iostream>

#define BIT_SIZE 8

// default constructor for obj declaration
Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
}

// default constructor for float
Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called\n";
	width = sizeof(fixed_point_val) * BITE_SIZE;
	fixed_point_val = Fixed::toFixedPoint(n, width, fractional_bits);
}

// default constructor for int
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	width = sizeof(fixed_point_val) * BITE_SIZE;
	fixed_point_val = toFixedPoint(n, width, fractional_bits);
}

// copy constructor
Fixed::Fixed(Fixed const &obj)
{
	std::cout << "Copy constructor called\n";
	fixed_point_val = obj.fixed_point_val;
	width = sizeof(fixed_point_val) * BITE_SIZE;
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called\n";
	fixed_point_val = obj.fixed_point_val;
	width = sizeof(fixed_point_val) * BITE_SIZE;
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

void Fixed::setRawBits(const int n)
{
	std::cout << "setRawBits member function called\n";
	fixed_point_val = n;
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
