#include "HoldingValue.hpp"
#include <stdexcept>
#include <iostream>

HoldingValue::HoldingValue(std::string s) : Value(strtof(s.c_str(), NULL))
{
	this->validateInput();
	std::cout << value << "\n";
}

void HoldingValue::validateInput(void)
{
	if (value < 0 || value > 1000)
		throw std::runtime_error("holding value out of range\n");
}
HoldingValue::HoldingValue(void) {}
HoldingValue::HoldingValue(const HoldingValue &obj)
{
	(void)obj;
}
HoldingValue &HoldingValue::operator=(const HoldingValue &obj)
{
	(void)obj;
	return *this;
}
HoldingValue ::~HoldingValue(void) {}
