#include "Span.hpp"

#include <stdexcept>

void Span::addNumber(int num)
{
	if (last_size == max_size)
		throw std::runtime_error("container capacity full\n");

	elements.push_back(num);
	last_size++;
}
