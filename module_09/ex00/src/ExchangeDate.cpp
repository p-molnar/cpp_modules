#include "ExchangeDate.hpp"
#include "utils.hpp"
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <map>

ExchangeDate::ExchangeDate(void)
{
	date_s = "";
	date.y = 0;
	date.m = 0;
	date.d = 0;
}
ExchangeDate::ExchangeDate(const ExchangeDate &obj)
{
	date_s = obj.date_s;
	date.y = obj.date.y;
	date.m = obj.date.m;
	date.d = obj.date.d;
}

ExchangeDate &ExchangeDate::operator=(const ExchangeDate &obj)
{
	date_s = obj.date_s;
	date.y = obj.date.y;
	date.m = obj.date.m;
	date.d = obj.date.d;
	return *this;
}

ExchangeDate::~ExchangeDate(void) {}

ExchangeDate::ExchangeDate(std::string date_input)
{
	std::vector<std::string> date_parts = split(date_input, "-");

	if (date_parts.size() != 3)
		throw(std::runtime_error("invalid date format\n"));

	if (date_parts[0].length() != 4)
		throw(std::runtime_error("year must be of YYYY representation\n"));

	if (date_parts[1].length() != 2)
		throw(std::runtime_error("month value must be of MM representation\n"));

	if (date_parts[2].length() != 2)
		throw(std::runtime_error("day value must be of DD representation\n"));

	int y = stod(date_parts[0]);
	int m = stod(date_parts[1]);
	int d = stod(date_parts[2]);

	std::map<int, int> day_count_per_month;
	day_count_per_month[1] = 31;
	day_count_per_month[2] = (y % 4 == 0) ? 29 : 28;
	day_count_per_month[3] = 31;
	day_count_per_month[4] = 30;
	day_count_per_month[5] = 31;
	day_count_per_month[6] = 30;
	day_count_per_month[7] = 31;
	day_count_per_month[8] = 31;
	day_count_per_month[9] = 30;
	day_count_per_month[10] = 31;
	day_count_per_month[11] = 30;
	day_count_per_month[12] = 31;

	if (y < 0)
		throw(std::runtime_error("year out of bound"));

	if (m <= 0 || m > 12)
		throw(std::runtime_error("month out of bound"));

	if (d <= 0 || d > day_count_per_month[m])
		throw(std::runtime_error("day out of bound"));

	this->date_s = date_input;
	date.y = y;
	date.m = m;
	date.d = d;
}

std::string ExchangeDate::getDateString(void) const
{
	return date_s;
}

bool operator<(const ExchangeDate &lhs, const ExchangeDate &rhs)
{
	return lhs.getDateString() < rhs.getDateString();
}

bool operator==(const ExchangeDate &lhs, const ExchangeDate &rhs)
{
	return lhs.getDateString() == rhs.getDateString();
}

std::ostream &operator<<(std::ostream &os, const ExchangeDate &obj)
{
	os << obj.getDateString();
	return os;
}