#include "Zombie.hpp"
#include <cstdlib>

int main(void)
{

	Zombie *heap_zombie = newZombie("Heap Zombie");
	heap_zombie->announce();
	delete heap_zombie;

	randomChump("Stack Zombie");
	return EXIT_SUCCESS;
}
