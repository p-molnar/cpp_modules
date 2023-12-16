#include <string>
#include <iostream>
#include <list>

std::list<std::string> split(std::string s, std::string sep = " ")
{
	std::list<std::string> lst;

	std::string word = "";
	for (size_t i = 0; i < s.length(); i++)
	{
		char curr_char = s[i];
		if (sep.find(curr_char) == std::string::npos)
			word += curr_char;
		else
		{
			lst.push_back(word);
			word.clear();
		}
	}
	lst.push_back(word);
	return lst;
}
