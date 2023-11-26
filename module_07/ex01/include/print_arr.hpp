#ifndef PRINT_ARR__HPP
#define PRINT_ARR__HPP

#include <iostream>

template <typename T>
void print_arr(T *array, int len)
{
	for (int i = 0; i < len; i++)
		std::cout << array[i] << '\n';
}
#endif
