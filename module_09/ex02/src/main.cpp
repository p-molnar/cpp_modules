#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include "Parser.hpp"
#include "Timer.hpp"

template <typename C>
void print_container_content(const C &container)
{
	for (size_t i = 0; i < container.size(); i++)
	{
		std::cout << container[i] << " ";
		if (i == 9)
		{
			std::cout << "[...]";
			break;
		}
	}
}

int main(int argc, char *argv[])
{

	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe <number sequence>\n";
		return EXIT_FAILURE;
	}

	try
	{
		Timer timer;

		// sort vector with merge insertion
		std::vector<int> v = Parser::loadData<std::vector<int> >(argv);
		std::cout << "Before: ";
		print_container_content(v);
		std::cout << '\n';

		timer.startTimer();
		std::vector<int> sorted_v = PmergeMe::sort(v);
		timer.stopTimer();

		std::cout << "After: ";
		print_container_content(sorted_v);
		std::cout << '\n';

		std::cout << "time to process " << v.size()
				  << " elements with PmergeMe::sort: ";
		std::cout << timer.getTimeElapsed() << "us";
		std::cout << std::endl;

		std::cout << std::endl;

		// sort deque with merge insertion
		std::deque<int> d = Parser::loadData<std::deque<int> >(argv);
		std::cout << "Before: ";
		print_container_content(d);
		std::cout << '\n';

		timer.startTimer();
		std::deque<int> sorted_d = PmergeMe::sort(d);
		timer.stopTimer();

		std::cout << "After: ";
		print_container_content(sorted_d);
		std::cout << '\n';

		std::cout << "time to process " << d.size()
				  << " elements with PmergeMe::sort: ";
		std::cout << timer.getTimeElapsed() << "us";
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
