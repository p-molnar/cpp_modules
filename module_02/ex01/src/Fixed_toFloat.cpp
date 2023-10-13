#include "Fixed.hpp"

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
