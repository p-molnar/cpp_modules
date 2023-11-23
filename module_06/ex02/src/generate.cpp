#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(bool print_generated_class_name = false)
{
	// initialise random seed
	srand(time(NULL));

	const int arr_size = 3;
	const int idx = rand() % arr_size;

	char class_name[arr_size] = {'A', 'B', 'C'};
	Base *class_arr[arr_size] = {new A(), new B(), new C()};

	for (int i = 0; i < arr_size; i++)
	{
		if (i != idx)
			delete class_arr[i];
	}

	if (print_generated_class_name)
		std::cout << class_name[idx] << '\n';
	return class_arr[idx];
}
