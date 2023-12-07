#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe <number sequence>\n";
		return EXIT_FAILURE;
	}

	PmergeMe Sorter;

	try
	{
		Sorter.load_data(argv);
		Sorter.sort_data();
		return EXIT_SUCCESS;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
}
