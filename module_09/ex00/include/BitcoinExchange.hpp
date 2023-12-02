#ifndef BITCOINEXCHANGE__HPP
#define BITCOINEXCHANGE__HPP

#include <map>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &obj);
	BitcoinExchange &operator=(const BitcoinExchange &obj);
	~BitcoinExchange(void);

	// load data
public:
	void loadExchangeData(std::string path);
	void loadHoldingData(std::string path);

	// private:
};

#endif
