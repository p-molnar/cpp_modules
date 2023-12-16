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

ExchangeRate BitcoinExchange::getClosestExchangeRate(const ExchangeDate &date)
{
	ExchangeRate rate;
	try
	{
		rate = rates.at(date);
	}
	catch (const std::exception &e)
	{
		std::map<ExchangeDate, ExchangeRate>::iterator it = rates.begin();

		while (it->first < date && it != rates.end())
			it++;
		rate = it->second;
	}

	return rate;
}

float operator*(const HoldingValue &value, const ExchangeRate &exchange_rate)
{
	return value.getValue() * exchange_rate.getValue();
}
