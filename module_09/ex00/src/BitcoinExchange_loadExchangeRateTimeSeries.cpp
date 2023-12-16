#include "utils.hpp"
#include "BitcoinExchange.hpp"
#include "ExchangeDate.hpp"
#include "ExchangeRate.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <iterator>

void BitcoinExchange::loadExchangeRateTimeSeries(std::string path)
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
			std::list<std::string> parts = split(line, ",");
			if (parts.size() != 2)
				throw std::runtime_error("bad input: 2 required fields: date, exchange_rate");

			std::list<std::string>::iterator it = parts.begin();

			ExchangeDate date(*it);
			std::advance(it, 1);
			ExchangeRate exchange_rate(*it);

			rates[date] = exchange_rate;
		}
	}
	else
		std::cout << "Error: " << strerror(errno) << '\n';
}
