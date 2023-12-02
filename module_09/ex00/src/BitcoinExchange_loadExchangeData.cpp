#include "utils.hpp"
#include "BitcoinExchange.hpp"
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
		bool is_first_line = true;
		while (std::getline(file, line))
		{
			// skip header
			if (is_first_line)
			{
				is_first_line = false;
				continue;
			}
			std::vector<std::string> parts = split(line, ",");
			if (parts.size() != 2)
				throw std::runtime_error("parse error: line contains too many data");
			std::string date = trim(parts[0]);
			int x_rate = strtod(trim(parts[1]).c_str(), NULL);
			if (x_rate < 0)
				throw std::runtime_error("parse error: negative exchange rate");
			std::cout << "date: '" << date << "' x_rate: '" << x_rate << "'\n";
		}
	}
	else
		std::cout << "Unable to open file\n";
}
