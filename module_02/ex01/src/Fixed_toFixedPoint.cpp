#include "Fixed.hpp"
#include <iostream>

int Fixed::getTwosComplement(int binary, int width, const int bin_point_pos)
{
	int twos_complement = 0;
	int integer_bits = binary;

	integer_bits = ~integer_bits;
	integer_bits += (1 << bin_point_pos);
	for (int i = width - 1; i >= 0; i--)
	{
		if (i >= bin_point_pos)
			twos_complement |= ((integer_bits >> i) & 1) << i;
		else
			twos_complement |= ((binary >> i) & 1) << i;
	}
	return twos_complement;
}

int Fixed::toFixedPoint(const float val, const int width, const int bin_point_pos)
{
	int fixed_point_val = 0;
	float num = val < 0 ? -val : val;
	float place_val;

	for (int i = width - 1; i >= 0; i--)
	{
		if (i >= bin_point_pos)
		{
			place_val = 1 << (i - bin_point_pos);
			if (place_val <= num)
			{
				fixed_point_val |= 1 << i;
				num -= place_val;
			}
		}
		else
		{
			place_val = 1.0f / (1 << (bin_point_pos - i));
			if (place_val <= num)
			{
				fixed_point_val |= 1 << i;
				num -= place_val;
			}
		}
	}
	fixed_point_val = val < 0 ? getTwosComplement(fixed_point_val, width, bin_point_pos) : fixed_point_val;
	return (fixed_point_val);
}

int Fixed::toFixedPoint(const int val, const int width, const int bin_point_pos)
{
	int fixed_point_val = 0;
	float num = val < 0 ? -val : val;
	float place_val;

	for (int i = width - 1; i >= bin_point_pos; i--)
	{
		place_val = 1 << (i - bin_point_pos);
		if (place_val <= num)
		{
			fixed_point_val |= 1 << i;
			num -= place_val;
		}
	}
	fixed_point_val = val < 0 ? getTwosComplement(fixed_point_val, width, bin_point_pos) : fixed_point_val;
	return (fixed_point_val);
}
