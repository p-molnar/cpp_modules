#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

unsigned int Span::longestSpan(void)
{
	if (elements.size() < 2)
		throw std::runtime_error("no span can be found");

	int min_el = *std::min_element(elements.begin(), elements.end());
	int max_el = *std::max_element(elements.begin(), elements.end());

	return max_el - min_el;
}
