#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
	: rates(obj.rates)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	rates = obj.rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

std::ostream &operator<<(std::ostream &os, BitcoinExchange &data)
{

	std::map<ExchangeDate, ExchangeRate>::iterator it;

	for (it = data.rates.begin(); it != data.rates.end(); it++)
	{
		os << it->first // string (key)
		   << ':'
		   << it->second // string's value
		   << std::endl;
	}
	return os;
}
