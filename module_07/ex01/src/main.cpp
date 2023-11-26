#include "iter.hpp"
#include "print_arr.hpp"
#include "template_fn.hpp"
#include <cstdlib>

int main(void)
{
	const int size = 5;
	{
		int arr[size] = {1, 2, 3, 4, 5};
		iter(arr, size, halve_num);
		print_arr(arr, size);
	}

	std::cout << std::endl;

	{
		int arr[size] = {1, 2, 3, 4, 5};
		iter(arr, size, double_num);
		print_arr(arr, size);
	}

	std::cout << std::endl;

	{
		double arr[size] = {1, 2, 3, 4, 5};
		iter(arr, size, halve_num);
		print_arr(arr, size);
	}

	std::cout << std::endl;

	{
		double arr[size] = {1, 2, 3, 4, 5};
		iter(arr, size, double_num);
		print_arr(arr, size);
	}
	return EXIT_SUCCESS;
}
