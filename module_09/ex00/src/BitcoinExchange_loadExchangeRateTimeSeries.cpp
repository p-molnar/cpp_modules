#include "utils.hpp"
#include "BitcoinExchange.hpp"
#include "ExchangeDate.hpp"
#include "ExchangeRate.hpp"
#include <string>
#include <iostream>
#include <fstream>

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
			std::vector<std::string> parts = split(line, ",");
			if (parts.size() != 2)
				throw std::runtime_error("bad input: 2 required fields: date, exchange_rate");

			ExchangeDate date(parts[0]);
			ExchangeRate exchange_rate(parts[1]);

			rates[date] = exchange_rate;
		}
	}
	else
		std::cout << "Error: " << strerror(errno) << '\n';
}
