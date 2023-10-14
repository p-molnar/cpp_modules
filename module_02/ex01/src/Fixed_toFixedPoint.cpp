#include "Fixed.hpp"
#include <iostream>

int Fixed::getTwosComplement(int n, int width, const int bin_point_pos)
{
	int twos_complement = 0;
	int integer_bits = n;

	integer_bits = ~integer_bits;
	integer_bits += (1 << bin_point_pos);
	for (int i = width - 1; i >= 0; i--)
	{
		if (i >= bin_point_pos)
			twos_complement |= ((integer_bits >> i) & 1) << i;
		else
			twos_complement |= ((n >> i) & 1) << i;
	}
	return twos_complement;
}

int Fixed::toFixedPoint(const float n, const int width, const int bin_point_pos)
{
	int fpv = 0;
	float num = n < 0 ? -n : n;
	float place_val;

	for (int i = width - 1; i >= 0; i--)
	{
		if (i >= bin_point_pos)
		{
			place_val = 1 << (i - bin_point_pos);
			if (place_val <= num)
			{
				fpv |= 1 << i;
				num -= place_val;
			}
		}
		else
		{
			place_val = 1.0f / (1 << (bin_point_pos - i));
			if (place_val <= num)
			{
				fpv |= 1 << i;
				num -= place_val;
			}
		}
	}
	fpv = n < 0 ? getTwosComplement(fpv, width, bin_point_pos) : fpv;
	return (fpv);
}

int Fixed::toFixedPoint(const int n, const int width, const int bin_point_pos)
{
	int fpv = 0;
	float num = n < 0 ? -n : n;
	float place_val;

	for (int i = width - 1; i >= bin_point_pos; i--)
	{
		place_val = 1 << (i - bin_point_pos);
		if (place_val <= num)
		{
			fpv |= 1 << i;
			num -= place_val;
		}
	}
	fpv = n < 0 ? getTwosComplement(fpv, width, bin_point_pos) : fpv;
	return (fpv);
}
