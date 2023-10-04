#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "invalid argument count: " << argc << '\n';
		std::cout << "Usage: ./replace <file name> "
				  << "<find word> <replace word>" << std::endl;
		return EXIT_FAILURE;
	}

	std::string in_file_name = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream in_file(in_file_name);
	if (in_file.is_open())
	{
		std::string out_file_name = in_file_name + ".replace";
		std::ofstream out_file(out_file_name);
		if (out_file.is_open())
		{
			std::string content;
			std::string new_string;
			while (getline(in_file, content))
			{
				size_t position = content.find(s1);
				while (position != std::string::npos && s1 != "")
				{
					new_string = content.substr(0, position);
					new_string += s2;
					new_string += content.substr(position + s1.length(), content.length());
					content = new_string;
					position = content.find(s1);
				}
				out_file << content;
			}
		}
		else
		{
			std::cout << out_file_name << " can't be created\n";
			return EXIT_FAILURE;
		}
		out_file.close();
	}
	else
	{
		std::cout << "'" << in_file_name << "'"
				  << " can't be opened\n";
		return EXIT_FAILURE;
	}
	in_file.close();
}
