#ifndef BITCOINEXCHANGE__HPP
#define BITCOINEXCHANGE__HPP

#include <map>
#include <string>
#include <iostream>
#include "ExchangeDate.hpp"
#include "ExchangeRate.hpp"
#include "HoldingValue.hpp"

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &obj);
	BitcoinExchange &operator=(const BitcoinExchange &obj);
	~BitcoinExchange(void);

	// load data
public:
	void exchangeHoldings(std::string path);
	void loadExchangeRateTimeSeries(std::string path);

private:
	ExchangeRate getClosestExchangeRate(const ExchangeDate &date);

public:
	std::map<ExchangeDate, ExchangeRate> rates;
};

std::ostream &operator<<(std::ostream &os, BitcoinExchange &data);

float operator*(const HoldingValue &value, const ExchangeRate &exchange_rate);

#endif
