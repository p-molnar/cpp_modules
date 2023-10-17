#include "Fixed.hpp"
#include <iostream>

int Fixed::toInt(void) const
{
	int n = 0;
	int place_val;
	int bin_val;
	bool is_first_iter = true;

	for (int i = width - 1; i >= fractional_bits; i--)
	{
		place_val = 1 << (i - fractional_bits);
		bin_val = ((num >> i) & 1);

		if (is_first_iter)
		{
			n -= bin_val * place_val;
			is_first_iter = false;
		}
		else
			n += bin_val * place_val;
	}
	return n;
}
