#ifndef ITER__HPP
#define ITER__HPP

#include <iostream>

template <typename T, typename Func>
void iter(T *array, int len, Func fn)
{
	for (int i = 0; i < len; i++)
		fn(array[i]);
}

#endif
