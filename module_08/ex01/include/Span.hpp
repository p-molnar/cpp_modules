#ifndef SPAN__HPP
#define SPAN__HPP

#include <vector>

class Span
{
private:
	std::vector<int> elements;
	unsigned int last_size;
	unsigned int max_size;

public:
	Span(void);
	Span(unsigned int N);
	Span(const Span &obj);
	Span &operator=(const Span &obj);
	~Span(void);

public:
	void addNumber(int);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);
};

#endif
