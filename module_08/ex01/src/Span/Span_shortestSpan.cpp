#include "Span.hpp"
#include <algorithm>
#include <vector>

unsigned int Span::shortestSpan(void)
{
	if (elements.size() < 1)
		throw std::runtime_error("No span can be found");

	std::vector<int> elements_copy = elements;
	std::sort(elements_copy.begin(), elements_copy.end());

	int smallest_diff;
	int tmp_diff;
	std::vector<int>::iterator it = elements_copy.begin();
	std::vector<int>::iterator ite = elements_copy.end() - 1;

	while (it != ite)
	{
		tmp_diff = *(it + 1) - *it;
		if (it == elements_copy.begin())
		{
			smallest_diff = tmp_diff;
		}
		else if (tmp_diff < smallest_diff)
		{
			smallest_diff = tmp_diff;
		}

		if (smallest_diff == 0)
			break;
		it++;
	}
	return smallest_diff;
}
