#include "utils.hpp"
#include "BitcoinExchange.hpp"
#include "ExchangeDate.hpp"
#include "ExchangeRate.hpp"
#include <string>
#include <iostream>
#include <fstream>

void BitcoinExchange::loadExchangeData(std::string path)
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
				throw std::runtime_error("parse error: line contains too many data");

			rates[ExchangeDate(parts[0])] = ExchangeRate(parts[1]);
		}
	}
	else
		std::cout << "Error: " << strerror(errno) << '\n';
}
