#include "Span.hpp"

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
