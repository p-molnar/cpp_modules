#include "Harl.hpp"
#include <string>
#include <iostream>

void Harl::complain(std::string level)
{
	const int level_count = 4;
	std::string levels[level_count] = {"DEBUG",
									   "INFO",
									   "WARNING",
									   "ERROR"};

	void (Harl::*func_ptrs[level_count])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	for (int i = 0; i < level_count; i++)
	{
		if (level == levels[i])
			(this->*func_ptrs[i])();
	}
}

void Harl::debug(void)
{
	std::cout << "debug\n";
}

void Harl::info(void)
{
	std::cout << "info\n";
}

void Harl::warning(void)
{
	std::cout << "warning\n";
}

void Harl::error(void)
{
	std::cout << "error\n";
}
