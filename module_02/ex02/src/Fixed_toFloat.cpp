#include "Fixed.hpp"

float Fixed::toFloat() const
{
	float result = 0.0f;
	bool is_negative;
	bool first_iter = true;

	for (int i = width - 1; i >= 0; i--)
	{
		int bin_val = (num >> i) & 1;
		int place_val = 1 << ABS((i - fractional_bits));

		if (i >= fractional_bits)
		{
			if (first_iter)
			{
				result -= bin_val * place_val;
				first_iter = false;
				is_negative = bin_val;
			}
			else
				result += bin_val * place_val;
		}
		else if (bin_val)
			result += (is_negative ? -1.0f : 1.0f) / place_val;
	}

	return result;
}
