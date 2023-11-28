#ifndef EASYFIND__HPP
#define EASYFIND__HPP

#include <stdexcept>

template <typename C>
int easyfind(const C &container, int lookup_val)
{
	typename C::const_iterator it;
	typename C::const_iterator ite = container.cend();
	unsigned int idx = 0;

	if (std::is_same<T, int>::value)
		throw

			for (it = container.cbegin(); it != ite; ++it, idx++)
		{
			if (*it == lookup_val)
				return idx;
		}
	throw(std::runtime_error("value not found"));
}

#endif
