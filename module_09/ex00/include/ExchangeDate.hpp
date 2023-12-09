#ifndef DATE__HPP
#define DATE__HPP

#include <string>

typedef struct
{
	unsigned int y;
	unsigned int m;
	unsigned int d;
} date_comp;

class ExchangeDate
{
public:
	ExchangeDate(void);
	ExchangeDate(std::string date);
	ExchangeDate(const ExchangeDate &obj);
	ExchangeDate &operator=(const ExchangeDate &obj);
	~ExchangeDate(void);

public:
	std::string getDateString(void) const;

private:
	std::string date_s;
	date_comp date;
};

bool operator<(const ExchangeDate &lhs, const ExchangeDate &rhs);
bool operator==(const ExchangeDate &lhs, const ExchangeDate &rhs);
std::ostream &operator<<(std::ostream &os, const ExchangeDate &obj);
#endif
