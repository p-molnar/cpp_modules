#include "HoldingValue.hpp"
#include <stdexcept>
#include <iostream>

HoldingValue::HoldingValue(std::string s) : Value(strtof(s.c_str(), NULL))
{
	this->validateInput();
}

HoldingValue::HoldingValue(void) : Value(0) {}

HoldingValue::HoldingValue(const HoldingValue &obj) : Value(obj.getValue()) {}

HoldingValue &HoldingValue::operator=(const HoldingValue &obj)
{
	value = obj.getValue();
	return *this;
}

HoldingValue ::~HoldingValue(void) {}

void HoldingValue::validateInput(void)
{
	if (value < 0 || value > 1000)
		throw std::runtime_error("holding value out of range\n");
}
