#ifndef EXCHANGERATE__HPP
#define EXCHANGERATE__HPP

#include "AValue.hpp"
#include <string>

class ExchangeRate : public Value
{

public:
	ExchangeRate(void);
	ExchangeRate(const ExchangeRate &obj);
	ExchangeRate &operator=(const ExchangeRate &obj);
	~ExchangeRate(void);
	ExchangeRate(std::string s);

private:
	void validateInput(void);
};

#endif
