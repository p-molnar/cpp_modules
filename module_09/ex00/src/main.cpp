#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc <holdings file path>\n";
		return EXIT_FAILURE;
	}

	BitcoinExchange btc_x;

	btc_x.loadExchangeRateTimeSeries("resources/data.csv");
	btc_x.exchangeHoldings(argv[1]);

	return EXIT_SUCCESS;
}
