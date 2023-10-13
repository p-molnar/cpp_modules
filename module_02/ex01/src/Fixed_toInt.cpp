#include "Fixed.hpp"

int Fixed::toInt(void) const
{
	int n = 0;
	int curr_place_val;
	int curr_bin_val;
	bool is_negative = fixed_point_val & (1 << (width - fractional_bits));

	for (int i = width - 1; i >= fractional_bits; i--)
	{
		curr_place_val = 1 << (i - fractional_bits);
		curr_bin_val = (fixed_point_val >> (i - fractional_bits)) & 1;
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
