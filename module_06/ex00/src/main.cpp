#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
