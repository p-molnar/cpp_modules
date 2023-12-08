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
	template <typename C>
	void addNumber(C it, C ite)
	{
		elements.insert(elements.end(), it, ite);
	}
	void addNumber(int);
	void fillWithRandomValues(void);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);
};

#endif
