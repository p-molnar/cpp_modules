#include "easyfind.hpp"
#include <iostream>

#include <vector>
#include <deque>
#include <list>

template <typename C>
void print_elements(C container)
{
	typename C::const_iterator it = container.cbegin();
	typename C::const_iterator ite = container.cend();
	while (it != ite)
	{
		std::cout << *it << ", ";
		it++;
	}
	std::cout << std::endl;
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
		int lookup_val = 4;
		std::cout << "easyfind(vect, " << lookup_val << ")\n";
		std::cout << easyfind(vec, lookup_val) << '\n';
		lookup_val = -1;
		std::cout << "easyfind(vect, " << lookup_val << ")\n";
		try
		{
			std::cout << easyfind(vec, lookup_val) << '\n';
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
		int lookup_val = 4;
		std::cout << "easyfind(vect, " << lookup_val << ")\n";
		std::cout << easyfind(deq, lookup_val) << '\n';
		lookup_val = -1;
		std::cout << "easyfind(vect, " << lookup_val << ")\n";
		try
		{
			std::cout << easyfind(deq, lookup_val) << '\n';
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}

	// deque
	{
		std::cout << "list\n";
		std::list<int> lst;
		for (int count = 0; count < 6; ++count)
			lst.push_back(count);

		print_elements(lst);
		int lookup_val = 4;
		std::cout << "easyfind(vect, " << lookup_val << ")\n";
		std::cout << easyfind(lst, lookup_val) << '\n';
		lookup_val = -1;
		std::cout << "easyfind(vect, " << lookup_val << ")\n";
		try
		{
			std::cout << easyfind(lst, lookup_val) << '\n';
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}
}
