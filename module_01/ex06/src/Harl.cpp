#include "Harl.hpp"
#include <string>
#include <iostream>

int Harl::getStartLevel(std::string level)
{
	const int level_count = 4;
	std::string levels[level_count] = {"DEBUG",
									   "INFO",
									   "WARNING",
									   "ERROR"};

	for (int i = 0; i < level_count; i++)
	{
		if (level == levels[i])
			return i;
	}
	return -1;
}

void Harl::complain(std::string level)
{
	const int start_level = Harl::getStartLevel(level);
	switch (start_level)
	{
	case 0:
		Harl::debug();
	case 1:
		Harl::info();
	case 2:
		Harl::warning();
	case 3:
		Harl::error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my"
				 "7XL-double-cheese-triple-pickle-special-"
				 " ketchup burger. I really do!\n";
	std::cout << '\n';
}

void Harl::info(void)
{
	std::cout << "[ INFORM ]\n";
	std::cout << "I cannot believe adding extra bacon costs more "
				 "money. You didn't put enough bacon in my burger! "
				 "If you did, I wouldn't be asking for more!\n";
	std::cout << '\n';
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. "
				 "I've been coming for years whereas you started working"
				 "here since last month.\n";
	std::cout << '\n';
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
	std::cout << '\n';
}
