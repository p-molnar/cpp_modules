#include "Fixed.hpp"
#include <iostream>

#define BIT_SIZE 8

int Fixed::getTwosComplement(int binary)
{
	binary = ~binary;
	binary += 1;
	return binary;
}

int Fixed::toInt(void) const
{
	int n = 0;
	int curr_place_val;
	int curr_bin_val;
	int width = sizeof(fixed_point_val) * BIT_SIZE;
	bool is_negative = fixed_point_val & (1 << (width - fractional_bits));

	for (int i = width - 1; i >= fractional_bits; i--)
	{
		curr_place_val = 1 << (i - fractional_bits);
		curr_bin_val = (fixed_point_val & curr_place_val);
		if (i >= fractional_bits)
		{
			if (i == sizeof(fixed_point_val) && is_negative)
				n -= curr_place_val >> fractional_bits;
			else
				n += curr_bin_val * (curr_place_val >> fractional_bits);
		}
	}
	return n;
}
float Fixed::toFloat(void) const
{
	float f = 0;
	int curr_place_val;
	int curr_bin_val;
	int width = sizeof(fixed_point_val) * BIT_SIZE;
	bool is_negative = fixed_point_val & (1 << (width - fractional_bits));

	for (int i = width; i >= 0; i--)
	{
		curr_place_val = 1 << (i - fractional_bits);
		curr_bin_val = fixed_point_val & curr_place_val;
		if (i >= fractional_bits)
		{
			if (i == sizeof(fixed_point_val) && is_negative)
				f -= curr_place_val;
			else
				f += curr_bin_val * curr_place_val;
		}
		else
		{
			if (is_negative)
				f -= 1 / (curr_bin_val * curr_place_val);
			else
				f += 1 / (curr_bin_val * curr_place_val);
		}
	}
	return f;
}

int Fixed::toFixedPoint(const float val, const int width, const int bin_point_pos)
{
	int fixed_point_val = 0;
	float num = val < 0 ? -val : val;
	int shift_count = width;
	float place_val;

	while (shift_count >= 0)
	{
		if (shift_count >= bin_point_pos)
		{
			place_val = 1 << (shift_count - bin_point_pos);
			if (place_val <= num)
			{
				fixed_point_val |= 1 << shift_count;
				num -= place_val;
			}
		}
		else
		{
			place_val = 1.0f / (1 << (bin_point_pos - shift_count));
			if (place_val <= num)
			{
				fixed_point_val |= 1 << shift_count;
				num -= place_val;
			}
		}
		shift_count--;
	}
	fixed_point_val = val < 0 ? getTwosComplement(fixed_point_val) : fixed_point_val;
	return (fixed_point_val);
}

int Fixed::toFixedPoint(const int val, const int width, const int bin_point_pos)
{
	int fixed_point_val = 0;
	int num = val < 0 ? -val : val;
	int shift_count = width;
	int place_val;

	while (shift_count >= bin_point_pos)
	{
		if (shift_count >= bin_point_pos)
		{
			place_val = 1 << (shift_count - bin_point_pos);
			if (place_val <= num)
			{
				fixed_point_val |= 1 << shift_count;
				num -= place_val;
			}
		}
		shift_count--;
	}

	fixed_point_val = val < 0 ? getTwosComplement(fixed_point_val) : fixed_point_val;

	return (fixed_point_val);
}

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
