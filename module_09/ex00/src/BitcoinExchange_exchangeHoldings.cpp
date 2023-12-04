#include "utils.hpp"
#include "BitcoinExchange.hpp"
#include "ExchangeDate.hpp"
#include "HoldingValue.hpp"
#include <string>
#include <iostream>
#include <fstream>

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
				std::vector<std::string> parts = split(line, "|");
				if (parts.size() != 2)
					throw std::runtime_error("bad input => " + line);

				ExchangeDate date(parts[0]);
				HoldingValue value(parts[1]);
				ExchangeRate exchange_rate;
				exchange_rate = this->getClosestExchangeRate(date);
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
