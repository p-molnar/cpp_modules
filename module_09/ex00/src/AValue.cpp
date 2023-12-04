#include "AValue.hpp"
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <iostream>

Value::Value(void) : value(0) {}

Value::Value(const Value &obj) : value(obj.value) {}

Value &Value::operator=(const Value &obj)
{
	value = obj.value;
	return *this;
}

Value::~Value(void) {}

Value::Value(float val) : value(val) {}

float Value::getValue(void) const
{
	return value;
}

bool operator<(const Value &lhs, const Value &rhs)
{
	return lhs.getValue() < rhs.getValue();
}

std::ostream &operator<<(std::ostream &os, const Value &obj)
{
	os << obj.getValue();
	return os;
}
