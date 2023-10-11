#include <iostream>
#include <string>
#include <cstdlib>

int main(void)
{
	std::string s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;

	std::cout << "memory address of s: " << &s << '\n';
	std::cout << "memory address held by stringPTR: " << stringPTR << '\n';
	std::cout << "memory address held by stringREF: " << &stringREF << '\n';

	std::cout << "value of s: " << s << '\n';
	std::cout << "value pointed to by stringPTR: " << *stringPTR << '\n';
	std::cout << "value pointed to by stringREF: " << stringREF << '\n';

	return EXIT_SUCCESS;
}
