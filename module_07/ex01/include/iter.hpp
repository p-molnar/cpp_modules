#ifndef ITER__HPP
#define ITER__HPP

#include <iostream>

template <typename T>
void iter(T *array, int len, T fn(T))
{
	for (int i = 0; i < len; i++)
		array[i] = fn(array[i]);
}

#endif
