#include "MutantStack.hpp"
#include <list>
#include <iostream>
#include <iomanip>
#include <cstdlib>

int main()
{
	srand(time(NULL));
	{
		std::cout << "MutantStack<int>\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
		std::cout << "\n";
	}

	{
		std::cout << "std::list<int>\n";
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::list<int> s(lst);
		std::cout << "\n";
	}

	// requires C++11 compilation flag
	// std::cout << "MutantStack with range based loop\n";
	// {
	// 	MutantStack<int> mstack;
	// 	for (int i = 0; i < 5; i++)
	// 		mstack.push(i);

	// 	for (int el : mstack)
	// 		std::cout << el << '\n';
	// }

	{
		std::cout << "MutantStack<float>\n";
		MutantStack<float> mstack;
		for (int i = 0; i < 10; i++)
		{
			mstack.push(rand() % 10 / 10.0);
		}

		MutantStack<float>::iterator it = mstack.begin();
		MutantStack<float>::iterator ite = mstack.end();

		while (it != ite)
		{
			std::cout << std::setprecision(3);
			std::cout << std::fixed;
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::cout << '\n';
	}

	{
		std::cout << "MutantStack<bool>\n";
		MutantStack<bool> mstack;
		for (int i = 0; i < 10; i++)
		{
			mstack.push(rand() % 2);
		}

		MutantStack<bool>::iterator it = mstack.begin();
		MutantStack<bool>::iterator ite = mstack.end();

		while (it != ite)
		{
			std::cout << std::boolalpha << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::cout << '\n';
	}

	return EXIT_SUCCESS;
}
