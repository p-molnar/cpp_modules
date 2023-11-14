#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	// AForm a;
	ShrubberyCreationForm SCF("Daniel");
	RobotomyRequestForm RRF("Edward");
	PresidentialPardonForm PPR("Fiona");

	std::cout << "\n\n";

	// Bureaucrat B_err_1("Anna", 151);
	// Bureaucrat B_err_2("Anna", 0);

	AForm *scf = new ShrubberyCreationForm("abc");
	delete scf;

	Bureaucrat B_1("Anna", 120);
	B_1.executeForm(SCF);
	B_1.executeForm(RRF);
	B_1.executeForm(PPR);
	std::cout << "\n";

	Bureaucrat B_2("Bob", 40);
	B_2.executeForm(SCF);
	B_2.executeForm(RRF);
	B_2.executeForm(PPR);
	std::cout << "\n";

	Bureaucrat B_3("Carla", 5);
	B_3.executeForm(SCF);
	B_3.executeForm(RRF);
	B_3.executeForm(PPR);
	std::cout << "\n";

	Intern intern;

	try
	{
		// AForm *form = intern.makeForm("presidential pardon", "target");
		AForm *form = intern.makeForm("non existing form", "target");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	return EXIT_SUCCESS;
}
