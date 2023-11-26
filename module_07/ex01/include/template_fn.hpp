#ifndef TEMPLATE_FN__HPP
#define TEMPLATE_FN__HPP

#include <iostream>

template <typename T>
T double_num(T number)
{
	return 2 * number;
}

template <typename T>
T halve_num(T number)
{
	return number / 2.0;
}
#endif
