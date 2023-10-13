#include "Fixed.hpp"

int Fixed::getTwosComplement(int binary)
{
	binary = ~binary;
	binary += 1;
	return binary;
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
