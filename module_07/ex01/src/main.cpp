#include "iter.hpp"
#include "template_fn.hpp"
#include <cstdlib>

int main(void)
{
	const int size = 5;
	{
		int arr[size] = {1, 2, 3, 4, 5};
		iter(arr, size, halve_num<int>);
	}

	std::cout << std::endl;

	{
		int arr[size] = {1, 2, 3, 4, 5};
		iter(arr, size, double_num<int>);
	}

	std::cout << std::endl;

	{
		double arr[size] = {1, 2, 3, 4, 5};
		iter(arr, size, halve_num<double>);
	}

	std::cout << std::endl;

	{
		double arr[size] = {1, 2, 3, 4, 5};
		iter(arr, size, double_num<double>);
	}
	return EXIT_SUCCESS;
}
