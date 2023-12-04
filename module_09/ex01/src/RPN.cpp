#include "RPN.hpp"
#include <cstdlib>
#include <iostream>

RPN::RPN(void) {}

RPN::RPN(const RPN &obj) : input(obj.input), s(obj.s) {}

RPN &RPN::operator=(const RPN &obj)
{
	input = obj.input;
	s = obj.s;
	return *this;
}

RPN::~RPN(void) {}

RPN::RPN(std::string input) : input(input) {}

void RPN::validateInput(char c)
{
	static bool space_flag = true;
	std::string operators = "+-/*";

	if (space_flag)
	{
		if (!(std::isdigit(c) || operators.find(c) != std::string::npos))
			throw std::runtime_error("Error");
		space_flag = false;
	}
	else
	{
		if (!std::isspace(c))
			throw std::runtime_error("Error");
		space_flag = true;
	}
}

void RPN::evaluateExpression(void)
{
	std::string operators = "+-/*";

	for (size_t i = 0; i < input.length(); i++)
	{
		if (std::isspace(input[i]))
			continue;
		else if (std::isdigit(input[i]))
		{
			s.push(input[i] - '0');
		}
		else if (operators.find(input[i]) != std::string::npos)
		{
			if (s.size() != 2)
				throw std::runtime_error("Error");

			int result = 0;
			int lhs = s.top();
			s.pop();
			int rhs = s.top();
			s.pop();
			if (input[i] == '+')
				result += lhs + rhs;
			else if (input[i] == '-')
				result += lhs - rhs;
			else if (input[i] == '/')
			{
				if (rhs)
					throw std::runtime_error("Error");
				result += lhs / rhs;
			}
			else
				result += lhs * rhs;
			s.push(result);
		}
	}
	std::cout << s.top() << "\n";
}
