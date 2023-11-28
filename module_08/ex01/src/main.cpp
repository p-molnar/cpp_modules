#include "Span.hpp"
#include <iostream>

int main(void)
{
	{
		Span sp = Span(5);
		try
		{
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
	}

	std::cout << std::endl;

	{
		Span sp = Span(5);
		try
		{
			for (int i = 0; i < 5; i++)
			{
				sp.addNumber(i);
			}
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
	}

	std::cout << std::endl;

	{
		Span sp = Span(1);
		try
		{
			sp.addNumber(2);
			sp.addNumber(3);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
	}

	std::cout << std::endl;

	{
		Span sp = Span(1);
		try
		{
			sp.addNumber(2);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
	}

	std::cout << std::endl;

	{
		Span sp = Span(10);
		try
		{
			std::vector<int> vec(5, 10);
			sp.addNumber(std::begin(vec), std::end(vec));

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
	}

	std::cout << std::endl;

	{
		Span sp = Span(100000);
		try
		{
			sp.fillWithRandomValues();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
	}
}
