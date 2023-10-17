#include "Fixed.hpp"
#include <iostream>

int Fixed::toInt(void) const
{
	int result = 0;
	int place_val;
	int bin_val;
	bool is_first_iter = true;

	for (int i = width - 1; i >= fractional_bits; i--)
	{
		place_val = 1 << (i - fractional_bits);
		bin_val = ((fpv >> i) & 1);

		if (is_first_iter)
		{
			result -= bin_val * place_val;
			is_first_iter = false;
		}
		else
			result += bin_val * place_val;
	}
	return result;
}
