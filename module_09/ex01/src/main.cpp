#include <iostream>
#include <cstdlib>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./rpn <rpn expression>\n";
		return EXIT_FAILURE;
	}

	RPN solver(argv[1]);

	try
	{
		solver.evaluateExpression();
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
}
