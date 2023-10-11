#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

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

	std::ifstream in_file(in_file_name.c_str());
	if (in_file.is_open())
	{
		std::string out_file_name = in_file_name + ".replace";
		std::ofstream out_file(out_file_name.c_str());
		if (out_file.is_open())
		{
			std::string line;
			std::string line_replaced;
			int s1_len = s1.length();
			int len;
			while (std::getline(in_file, line))
			{
				line_replaced = "";
				int i = 0;
				char *line_c_str = (char *)line.c_str();
				len = line.length();
				std::string tmp;
				while (i < len)
				{
					tmp = &line_c_str[i];
					if (tmp.find(s1) != 0 || s1 == "")
						line_replaced += line_c_str[i];
					else
					{
						line_replaced += s2;
						i += s1_len - 1;
					}
					i++;
				}
				out_file << line_replaced << (in_file.eof() ? "" : "\n");
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
