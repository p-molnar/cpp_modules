#ifndef HOLDINGVALUE__HPP
#define HOLDINGVALUE__HPP

#include "AValue.hpp"
#include <string>

class HoldingValue : public Value
{
public:
	HoldingValue(void);
	HoldingValue(const HoldingValue &obj);
	HoldingValue &operator=(const HoldingValue &obj);
	~HoldingValue(void);

public:
	HoldingValue(std::string s);

public:
	void validateInput(void);
};


#endif
