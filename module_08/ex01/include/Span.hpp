#ifndef SPAN__HPP
#define SPAN__HPP

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

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
	void print_vec(void);

public:
	void addNumber(int);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);

	template <typename C>
	void fill(C it, C ite)
	{
		while (it != ite)
		{
			if (last_size < max_size)
				elements.push_back(*it);
			else
				break;
			last_size++;
			it++;
		}
	}

	void fillWithRandomValues(void)
	{
		srand(time(NULL));
		for (int i = 0; i < static_cast<int>(max_size); i++)
		{
			if (last_size < max_size)
				elements.push_back(rand());
			else
				break;
			last_size++;
		}
	}
};

std::ostream &operator<<(std::ostream &os, const Span &sp);
#endif
