#include <iostream>
#include <cstring>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		int len = strlen(argv[i]);
		for (int j = 0; j < len; j++)
			argv[i][j] = toupper(argv[i][j]);
		std::cout << argv[i];
	}
	std::cout << '\n';
	return EXIT_SUCCESS;
}
