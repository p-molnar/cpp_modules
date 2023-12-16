#include "ExchangeRate.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <iomanip>

ExchangeRate::ExchangeRate(std::string s) : Value(strtof(s.c_str(), NULL))
{
	this->validateInput();
}

ExchangeRate::ExchangeRate(void) : Value(0) {}

ExchangeRate::ExchangeRate(const ExchangeRate &obj) : Value(obj.getValue()) {}

ExchangeRate &ExchangeRate::operator=(const ExchangeRate &obj)
{
	value = obj.getValue();
	return *this;
}

ExchangeRate ::~ExchangeRate(void) {}

void ExchangeRate::validateInput(void)
{
	if (value < 0)
		throw(std::runtime_error("negative exchange rate"));
}
