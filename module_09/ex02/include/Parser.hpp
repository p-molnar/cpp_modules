#ifndef PARSER__HPP
#define PARSER__HPP

#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#define DECIMAL 10

class Parser
{
private:
	Parser(void){};
	Parser(const Parser &obj) { (void)obj; };
	Parser &operator=(const Parser &obj)
	{
		(void)obj;
		return *this;
	};
	~Parser(void);

public:
	template <typename Container>
	static Container loadData(char *argv[])
	{
		Container container;
		for (int i = 1; argv[i] != NULL; i++)
		{
			long int parsed_val = strtol(argv[i], NULL, DECIMAL);
			if (parsed_val < 1)
			{
				throw std::runtime_error("Non positive input");
			}
			if (std::find(container.begin(), container.end(), parsed_val) != container.end())
			{
				throw std::runtime_error("Duplicate value");
			}
			container.push_back(parsed_val);
		}
		return container;
	};
};

#endif
