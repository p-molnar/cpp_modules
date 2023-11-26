#include "max.hpp"
#include "min.hpp"
#include "swap.hpp"
#include <iostream>

int main(void)
{
	{
		int a = 1;
		int b = 3;
		std::cout << "a = " << a << "; b = " << b << '\n';
		std::cout << "max(" << a << ", " << b << ") = " << max(a, b) << '\n';
		std::cout << "min(" << a << ", " << b << ") = " << min(a, b) << '\n';
		std::cout << "swap(" << a << ", " << b << ")\n";
		swap(a, b);
		std::cout << "a = " << a << "; b = " << b << '\n';
	}

	std::cout << std::endl;

	{
		float a = 1.5f;
		float b = 3.3f;
		std::cout << "a = " << a << "; b = " << b << '\n';
		std::cout << "max(" << a << ", " << b << ") = " << max(a, b) << '\n';
		std::cout << "min(" << a << ", " << b << ") = " << min(a, b) << '\n';
		std::cout << "swap(" << a << ", " << b << ")\n";
		swap(a, b);
		std::cout << "a = " << a << "; b = " << b << '\n';
	}

	std::cout << std::endl;

	{
		double a = 1.5134;
		double b = 3.332;
		std::cout << "a = " << a << "; b = " << b << '\n';
		std::cout << "max(" << a << ", " << b << ") = " << max(a, b) << '\n';
		std::cout << "min(" << a << ", " << b << ") = " << min(a, b) << '\n';
		std::cout << "swap(" << a << ", " << b << ")\n";
		swap(a, b);
		std::cout << "a = " << a << "; b = " << b << '\n';
	}
}
