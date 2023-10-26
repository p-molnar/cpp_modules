#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void leaks(void)
{
	system("leaks brain");
}

int Animal::c_id = 0;
int main(void)
{
	atexit(leaks);
	// tests for virtual destructor

	const int size = 5;
	Animal **animals = new Animal *[size];
	std::cout << '\n';

	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
		{
			std::cout << "dog #" << i << '\n';
			animals[i] = new Dog;
			std::cout << '\n';
		}
		else
		{
			std::cout << "cat #" << i << '\n';
			animals[i] = new Cat;
			std::cout << '\n';
		}
	}

	for (int i = 0; i < size; i++)
	{
		delete animals[i];
	}
	delete[] animals;

	// test for deep copies
	Dog dog_a;
	{
		Dog dog_b;
		std::cout << '\n';
		std::cout << "dog #" << dog_a.id << " brain address: " << dog_a.getBrainAddress() << '\n';
		std::cout << "dog #" << dog_a.id << " brain idea: " << dog_a.getBrain() << '\n';
		std::cout << "dog #" << dog_b.id << " brain address: " << dog_b.getBrainAddress() << '\n';
		std::cout << "dog #" << dog_b.id << " brain idea: " << dog_b.getBrain() << '\n';
		dog_a = dog_b;
	}

	std::cout << '\n';
	std::cout << "dog #" << dog_a.id << " brain address: " << dog_a.getBrainAddress() << '\n';
	std::cout << "dog #" << dog_a.id << " brain's mem address: " << dog_a.getBrain() << '\n';
}
