#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	(void)argc, (void)argv;
	BitcoinExchange btc_x;
	btc_x.loadExchangeData("/Users/pmolnar/Documents/Universities.nosync/Codam/42cursus/cpp/module_09/ex00/resources/data.csv");

	return EXIT_SUCCESS;
}
