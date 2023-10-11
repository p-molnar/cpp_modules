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
		&Harl::error};

	for (int i = 0; i < level_count; i++)
	{
		if (level == levels[i])
			(this->*func_ptrs[i])();
	}
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
