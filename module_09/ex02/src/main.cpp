#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include "Parser.hpp"
#include "Timer.hpp"

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
		std::vector<int> v = Parser::loadData<std::vector<int> >(argv);
		std::deque<int> d = Parser::loadData<std::deque<int> >(argv);

		timer.startTimer();
		std::vector<int> sorted_v = PmergeMe::sort(v);
		timer.stopTimer();
		std::cout << "timer: " << timer.getTimeElapsed() << '\n';
		// for (size_t i = 0; i < sorted_v.size(); i++)
		// {
		// 	std::cout << sorted_v[i] << " ";
		// }
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
