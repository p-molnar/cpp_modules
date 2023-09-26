#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
	std::string curr_arg{};

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		curr_arg = argv[i];
		for (int j = 0, len = curr_arg.length(); j < len; j++)
			std::cout << static_cast<char>(std::toupper(curr_arg[j]));
	}
	std::cout << '\n';
	return EXIT_SUCCESS;
}
