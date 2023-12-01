#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <list>
#include <vector>

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

			sp.print_vec();
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
			sp.print_vec();
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
			sp.print_vec();
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
			sp.print_vec();
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
		std::vector<int> v;
		v.insert(v.begin(), 5, 3);
		try
		{
			sp.fill(v.begin(), v.end());

			sp.print_vec();
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
		Span sp = Span(10000);
		try
		{
			sp.fillWithRandomValues();
			sp.print_vec();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
	}
	return EXIT_SUCCESS;
}
