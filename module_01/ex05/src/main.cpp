#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl harl;

	std::cout << "level = debug\n";
	harl.complain("DEBUG");

	std::cout << "level = info\n";
	harl.complain("INFO");

	std::cout << "level = warning\n";
	harl.complain("WARNING");

	std::cout << "level = error\n";
	harl.complain("ERROR");

	std::cout << "level = xyz\n";
	harl.complain("xyz");
}
