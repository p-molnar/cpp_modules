#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	validateForExecution(executor);

	const int buf_size = 512;
	char path_buf[buf_size];
	getcwd(path_buf, buf_size);
	std::string path = path_buf;
	path += "/" + this->getTarget() + "_shrubbery.txt";
	std::ofstream outfile(path.c_str());

	outfile << ".\n"
			   "└── Edit me to generate/\n"
			   "    ├── a/\n"
			   "    │   └── nice/\n"
			   "    │       └── tree/\n"
			   "    │           ├── diagram!\n"
			   "    │           └── :)\n"
			   "    └── Use indentation/\n"
			   "        ├── to indicate/\n"
			   "        │   ├── file\n"
			   "        │   ├── and\n"
			   "        │   ├── folder\n"
			   "        │   └── nesting.\n"
			   "        └── You can even/\n"
			   "            └── use/\n"
			   "                ├── markdown\n"
			   "                └── bullets!\n";
}
