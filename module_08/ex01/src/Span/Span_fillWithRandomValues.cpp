#include "Span.hpp"

#include <stdexcept>
#include <ctime>
#include <iostream>

void Span::fillWithRandomValues(void)
{
	srand(time(NULL));
	int count = max_size - last_size;
	for (int i = 0; i < count; i++)
	{
		try
		{
			addNumber(rand());
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}
	}
}
