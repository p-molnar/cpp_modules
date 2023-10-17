#include "Fixed.hpp"

void Fixed::printBin(int n)
{
	int j = 1;
	for (int i = 31; i >= 0; i--)
	{
		std::cout << ((n >> i) & 1);
		if (j > 0 && !(j % 8))
			std::cout << "  ";
		j++;
	}
	std::cout << '\n';
}
