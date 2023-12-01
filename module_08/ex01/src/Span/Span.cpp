#include "Span.hpp"
#include <iostream>

Span::Span() : last_size(0), max_size(0)
{
}

Span::Span(unsigned int N) : last_size(0), max_size(N)
{
}

Span::Span(const Span &obj)
	: elements(obj.elements),
	  last_size(obj.last_size),
	  max_size(obj.max_size)
{
}

Span &Span::operator=(const Span &obj)
{
	elements = obj.elements;
	max_size = obj.max_size;
	last_size = obj.last_size;
	return *this;
}

Span::~Span(void) {}

void Span::print_vec(void)
{
	std::vector<int>::iterator it = elements.begin();
	std::vector<int>::iterator ite = elements.end();

	if (elements.size() < 10)
	{
		while (it != ite)
		{
			std::cout << *it << " ";
			it++;
		}
	}
	else
	{
		int i = 0;
		while (it != ite && i < 5)
		{
			std::cout << *it << " ";
			i++;
		}

		std::cout << "[...] ";
		it = elements.begin() + (elements.size() - 5);
		i = 0;
		while (it != ite && i < 5)
		{
			std::cout << *it << " ";
			i++;
		}
	}
	std::cout << std::endl;
}
