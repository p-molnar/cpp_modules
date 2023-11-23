#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(bool print_generated_class_name = false);
void identify(Base *p);
void identify(Base &p);

int main(void)
{
	Base *rand_class_ptr = generate(true);
	Base &rand_class_ref = *rand_class_ptr;

	identify(rand_class_ptr);
	identify(rand_class_ref);
	return EXIT_SUCCESS;
}
