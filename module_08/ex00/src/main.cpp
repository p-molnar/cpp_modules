#include "easyfind.hpp"
#include <iostream>

#include <vector>
#include <deque>
#include <list>

template <typename C>
void print_elements(C container)
{
	for (typename C::iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << ", ";
}

int main(void)
{
	// vector
	{
		std::cout << "vector\n";
		std::vector<int> vec;
		for (int count = 0; count < 6; ++count)
			vec.push_back(count);

		print_elements(vec);
		std::cout << std::endl;
		int lookup_val = 4;
		std::cout << "easyfind(vec, " << lookup_val << ")\n";
		try
		{
			easyfind(vec, lookup_val);
			std::cout << "lookup_val is in container\n";
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		lookup_val = -1;
		std::cout << "easyfind(vec, " << lookup_val << ")\n";
		try
		{
			easyfind(vec, lookup_val);
			std::cout << "lookup_val is in container\n";
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}

	// deque
	{
		std::cout << "deque\n";
		std::deque<int> deq;
		for (int count = 0; count < 6; ++count)
			deq.push_back(count);

		print_elements(deq);
		std::cout << std::endl;
		int lookup_val = 4;
		std::cout << "easyfind(deq, " << lookup_val << ")\n";
		try
		{
			easyfind(deq, lookup_val);
			std::cout << "lookup_val is in container\n";
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		lookup_val = -1;
		std::cout << "easyfind(deq, " << lookup_val << ")\n";
		try
		{
			easyfind(deq, lookup_val);
			std::cout << "lookup_val is in container\n";
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}

	// list
	{
		std::cout << "list\n";
		std::list<int> lst;
		for (int count = 0; count < 6; ++count)
			lst.push_back(count);

		print_elements(lst);
		std::cout << std::endl;
		int lookup_val = 4;
		std::cout << "easyfind(lst, " << lookup_val << ")\n";
		try
		{
			easyfind(lst, lookup_val);
			std::cout << "lookup_val is in container\n";
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		lookup_val = -1;
		std::cout << "easyfind(lst, " << lookup_val << ")\n";
		try
		{
			easyfind(lst, lookup_val);
			std::cout << "lookup_val is in container\n";
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}
}
