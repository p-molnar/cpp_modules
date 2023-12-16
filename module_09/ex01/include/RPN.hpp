#ifndef RPN__HPP
#define RPN__HPP

#include <iostream>
#include <stack>

class RPN
{
public:
	RPN(void);
	RPN &operator=(const RPN &obj);
	RPN(const RPN &obj);
	~RPN(void);

	RPN(std::string input);

private:
	void validateInput(char c);

public:
	void evaluateExpression(void);
	double rpop(void);

private:
	std::string input;
	std::stack<double> s;
};

#endif
