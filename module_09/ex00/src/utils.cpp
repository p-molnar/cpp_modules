#include <string>
#include <vector>

std::string trim(std::string &s)
{
	std::string trimmed_s = "";
	for (size_t i = 0; i < s.length(); i++)
	{
		char curr_char = s[i];
		if (!std::isspace(curr_char))
			trimmed_s += curr_char;
	}
	return trimmed_s;
}

std::vector<std::string> split(std::string s, std::string sep = " ")
{
	std::vector<std::string> vec;

	std::string word = "";
	for (size_t i = 0; i < s.length(); i++)
	{
		char curr_char = s[i];
		if (sep.find(curr_char) == std::string::npos)
			word += curr_char;
		else
		{
			vec.push_back(word);
			word.clear();
		}
	}
	return vec;
}
