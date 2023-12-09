#include "utils.hpp"
#include "BitcoinExchange.hpp"
#include "ExchangeDate.hpp"
#include "HoldingValue.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <iterator>

void BitcoinExchange::exchangeHoldings(std::string path)
{
	std::ifstream file;
	file.open(path);

	if (file.is_open())
	{
		std::string line;

		// skip header of file
		std::getline(file, line);
		while (std::getline(file, line))
		{
			try
			{
				std::list<std::string> input_parts = split(line, "|");
				if (input_parts.size() != 2)
					throw std::runtime_error("bad input => " + line);

				std::list<std::string>::iterator it = input_parts.begin();

				ExchangeDate date(*it);
				std::advance(it, 1);
				HoldingValue value(*it);

				ExchangeRate exchange_rate = this->getClosestExchangeRate(date);

				std::cout << date << " => " << value << " = " << value * exchange_rate << "\n";
			}
			catch (const std::exception &e)
			{
				std::cerr << "Error: " << e.what() << '\n';
			}
		}
	}
	else
		std::cout << "Error: " << strerror(errno) << '\n';
}
