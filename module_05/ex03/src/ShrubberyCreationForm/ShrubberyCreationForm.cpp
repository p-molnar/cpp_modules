#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <unistd.h>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137)
{
	const int buf_size = 512;
	char path_buf[buf_size];
	getcwd(path_buf, buf_size);
	std::string path = path_buf;
	path += "/" + target + "_shrubbery.txt";
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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj.getName(), obj.getSignGrade(), obj.getExecuteGrade())
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	this->set_IsSigned(obj.getIsSigned());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
