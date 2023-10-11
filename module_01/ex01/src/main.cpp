#include "Zombie.hpp"
#include <cstdlib>

int main(void)
{
	const int horde_size = 5;
	Zombie *horde = zombieHorde(horde_size, "abc");

	for (int i = 0; i < horde_size; i++)
		horde[i].announce();

	delete[] horde;
	return EXIT_SUCCESS;
}
