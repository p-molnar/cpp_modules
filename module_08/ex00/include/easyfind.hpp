#ifndef EASYFIND__HPP
#define EASYFIND__HPP

#include <stdexcept>
#include <algorithm>

template <typename C>
void easyfind(const C &container, int lookup_val)
{
	typename C::const_iterator iter = std::find(container.cbegin(), container.cend(), lookup_val);

	if (iter == container.cend())
		throw(std::runtime_error("value not found"));
}

#endif
