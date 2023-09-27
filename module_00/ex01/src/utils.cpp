#include <iostream>

bool isNumeric(std::string s)
{
	int i{0};
	int len{static_cast<int>(s.length())};

	while (i < len)
	{
		if (i == 0 && (s[i] == '+' || s[i] == '-') && len > 1)
			i++;
		else if (isdigit(s[i]))
			i++;
		else
			return false;
	}
	return true;
}

bool isInRange(std::string input)
{
	constexpr int min{0};
	constexpr int max{7};
	int n{};

	if (!isNumeric(input))
	{
		std::cout << "index must of numeric type\n";
		return false;
	}

	n = stoi(input);
	if (n < min || n > max)
		return false;
	return true;
}

std::string prompt(std::string_view msg = "> ",
				   bool (*validator_fn)(std::string) = NULL,
				   std::string err_msg = "",
				   bool reprompt_on_fail = false)
{
	std::cout << msg;
	std::string input;
	std::getline(std::cin >> std::ws, input);
	if (reprompt_on_fail)
	{
		if (validator_fn && !validator_fn(input))
		{
			std::cout << err_msg;
			input = prompt(msg, validator_fn, err_msg, reprompt_on_fail);
		}
	}
	return input;
}

std::string stringSlice(std::string s, int start, int stop)
{
	std::string sliced_string{};
	for (int i = start; i < stop; i++)
		sliced_string += s[i];
	return (sliced_string);
}

