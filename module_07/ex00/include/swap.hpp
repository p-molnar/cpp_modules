#ifndef SWAP__HPP
#define SWAP__HPP

template <typename T>

void swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

#endif
