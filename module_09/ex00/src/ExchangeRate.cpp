#include "ExchangeRate.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <iomanip>

ExchangeRate::ExchangeRate(std::string s) : Value(strtof(s.c_str(), NULL))
{
	this->validateInput();
}

ExchangeRate::ExchangeRate(void) {}
ExchangeRate::ExchangeRate(const ExchangeRate &obj) { (void)obj; }
ExchangeRate &ExchangeRate::operator=(const ExchangeRate &obj)
{
	(void)obj;
	return *this;
}
ExchangeRate ::~ExchangeRate(void) {}

void ExchangeRate::validateInput(void)
{
	if (value < 0)
		throw(std::runtime_error("negative exchange rate"));
}

