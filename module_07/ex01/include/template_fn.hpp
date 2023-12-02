#ifndef TEMPLATE_FN__HPP
#define TEMPLATE_FN__HPP

#include <iostream>

template <typename T>
void double_num(T number)
{
	std::cout << 2 * number << '\n';
}

template <typename T>
void halve_num(T number)
{
	std::cout << number / 2.0 << '\n';
}
#endif
