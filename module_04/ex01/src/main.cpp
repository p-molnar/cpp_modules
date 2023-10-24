#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void leaks(void)
{
	system("leaks brain");
}

int main(void)
{
	atexit(leaks);
	Animal *cat = new Cat;
	std::cout << '\n';
	Animal *dog = new Dog;
	std::cout << '\n';

	Dog *dog_2 = new Dog;
	std::cout << '\n';
	Dog *dog_3;
	std::cout << '\n';
	dog_3 = dog_2;
	(void)dog_3;
	std::cout << cat->getType() << '\n';
	std::cout << dog->getType() << '\n';

	std::cout << '\n';
	delete cat;
	std::cout << '\n';
	delete dog;
}
