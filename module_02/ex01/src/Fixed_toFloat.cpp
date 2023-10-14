#include "Fixed.hpp"

float Fixed::toFloat(void) const
{
	float n = 0;
	int place_val, bin_val;
	bool is_first_iter = true;
	bool is_negative;

	for (int i = width - 1; i >= 0; i--)
	{
		bin_val = ((fixed_point_val >> i) & 1);
		if (i >= fractional_bits)
		{
			place_val = 1 << (i - fractional_bits);
			if (is_first_iter)
			{
				n -= bin_val * place_val;
				is_first_iter = false;
				is_negative = n < 0;
			}
			else
				n += bin_val * place_val;
		}
		else if (bin_val)
		{
			place_val = 1 << (fractional_bits - i);
			if (is_negative)
				n -= 1.0f / (bin_val * place_val);
			else
				n += 1.0f / (bin_val * place_val);
		}
	}
	return n;
}
