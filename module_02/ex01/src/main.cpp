#include <iostream>
#include <cstdlib>
#include "Fixed.hpp"

int main(void)
{
	Fixed a(2);

	std::cout << a.toInt() << '\n';
	// std::cout << a.getRawBits() << std::endl;
	// std::cout << b.getRawBits() << std::endl;
	// std::cout << c.getRawBits() << std::endl;
	return 0;
}
