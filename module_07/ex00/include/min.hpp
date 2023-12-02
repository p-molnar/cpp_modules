#ifndef MIN__HPP
#define MIN__HPP

template <typename T>

const T &min(const T &x, const T &y)
{
	return x < y ? x : y;
}

#endif
