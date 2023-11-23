#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
	else
	{
		std::cout << "Casting not possible\n";
		return;
	}
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A\n";
	}
	catch (const std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B\n";
		}
		catch (const std::exception &e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C\n";
			}
			catch (const std::exception &e)
			{
				std::cout << e.what();
			}
		}
	}
}
