#ifndef MAX__HPP
#define MAX__HPP

template <typename T>

const T &max(const T &x, const T &y)
{
	return x > y ? x : y;
}

#endif
