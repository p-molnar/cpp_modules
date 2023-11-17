#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	// Tests from ex00
	try
	{
		Bureaucrat B_1("Sophie", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "exception: " << e.what();
	}

	try
	{
		Bureaucrat B_2("Sophie", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "exception: " << e.what();
	}

	Bureaucrat B_3("Sophie", 1);
	try
	{
		B_3.increment();
	}
	catch (std::exception &e)
	{
		std::cout << "exception: " << e.what();
	}

	Bureaucrat B_4("Sophie", 150);
	try
	{
		B_4.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << "exception: " << e.what();
	}

	Bureaucrat B_5("Sophie", 40);
	std::cout << B_5 << '\n';
	B_5.increment();
	std::cout << B_5 << '\n';
	B_5.decrement();
	std::cout << B_5 << '\n';

	// tests for exercise ex01

	Form F_1("Form_1", 2, 4);

	try
	{
		Form F_2("Form_2", 0, 4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	try
	{
		Form F_3("Form_3", 2, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	try
	{
		Form F_4("Contract", 5, 8);
		Bureaucrat B_6("Sarah", 4);
		B_6.signForm(F_4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	try
	{
		Form F_5("Consultancy Agreement", 2, 8);
		Bureaucrat B_7("Sarah", 4);
		B_7.signForm(F_5);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	try
	{
		Form F_6("non-disclosure agreements", 15, 20);
		std::cout << F_6;
		Bureaucrat B_8("Gerogie", 3);
		B_8.signForm(F_6);
		std::cout << F_6;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return EXIT_SUCCESS;
}
