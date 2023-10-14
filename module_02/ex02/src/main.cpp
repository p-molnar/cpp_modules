#include <iostream>
#include <cstdlib>
#include "Fixed.hpp"

int main(void)
{
	Fixed a(-12);
	Fixed b(-12);

	std::cout << "a: " << a << '\n';
	std::cout << "b: " << b << '\n';
	std::cout << "a < b: " << (a < b) << '\n';
	std::cout << "a > b: " << (a > b) << '\n';
	std::cout << "a <= b: " << (a <= b) << '\n';
	std::cout << "a >= b: " << (a >= b) << '\n';
	std::cout << "a == b: " << (a == b) << '\n';
	std::cout << "a != b: " << (a != b) << '\n';

	std::cout << "\n";

	std::cout << "a + b: " << (a + b) << '\n';
	std::cout << "a - b: " << (a - b) << '\n';
	std::cout << "a * b: " << (a * b) << '\n';
	std::cout << "a / b: " << (a / b) << '\n';

	std::cout << "\n";

	std::cout << "a: " << a << '\n';
	std::cout << "a++: " << a++ << '\n';
	std::cout << "a: " << a << '\n';
	std::cout << "++a: " << ++a << '\n';
	std::cout << "a: " << a << '\n';

	std::cout << "\n";

	std::cout << "b: " << b << '\n';
	std::cout << "b--: " << b-- << '\n';
	std::cout << "b: " << b << '\n';
	std::cout << "--b: " << --b << '\n';
	std::cout << "b: " << b << '\n';

	std::cout << "min(a, b): " << Fixed::min(a, b) << '\n';
	std::cout << "max(a, b): " << Fixed::max(a, b) << '\n';
	return EXIT_SUCCESS;
}
