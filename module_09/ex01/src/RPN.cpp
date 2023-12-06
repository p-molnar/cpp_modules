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

double RPN::rpop(void)
{
	double return_val = s.top();
	s.pop();
	return return_val;
}

void RPN::evaluateExpression()
{
	for (size_t i = 0; i < input.length(); i++)
	{
		char curr_char = input[i];

		if (std::isspace(curr_char))
		{
			// skip whitespace
			continue;
		}
		else if (std::isdigit(curr_char))
		{
			// push numeric value onto the stack
			s.push(curr_char - '0');
		}
		else
		{
			// handle operators
			char operation = curr_char;

			if (s.size() < 2)
			{
				throw std::runtime_error("Insufficient operands for operation");
			}

			double result;
			double rhs = this->rpop();
			double lhs = this->rpop();

			switch (operation)
			{
			case '+':
				result = lhs + rhs;
				break;
			case '-':
				result = lhs - rhs;
				break;
			case '/':
				if (rhs == 0)
					throw std::runtime_error("Division by zero");
				result = lhs / rhs;
				break;
			case '*':
				result = lhs * rhs;
				break;
			default:
				throw std::runtime_error("Invalid operator");
			}

			s.push(result);
		}
	}

	if (s.size() != 1)
	{
		throw std::runtime_error("Invalid expression");
	}

	std::cout << this->rpop() << '\n';
}
