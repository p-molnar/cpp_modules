#ifndef VALUE__HPP
#define VALUE__HPP

#include <string>

class Value
{
public:
	Value(void);
	Value(const Value &obj);
	Value &operator=(const Value &obj);
	virtual ~Value(void);
	Value(float val);

private:
	virtual void validateInput(void) = 0;

	// getter
public:
	float getValue(void) const;

protected:
	float value;
};

bool operator<(const Value &lhs, const Value &rhs);
std::ostream &operator<<(std::ostream &os, const Value &obj);
#endif
