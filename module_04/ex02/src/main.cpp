#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <cstdlib>

int Animal::c_id = 0;

int main(void)
{
	srand(time(NULL));

	// test for abstract class
	Animal test_animal_1;
	Animal *test_animal_2 = new Animal;

	// tests for virtual destructor
	const int size = 5;
	Animal **animals = new Animal *[size];
	std::cout << '\n';

	for (int i = 0; i < size; i++)
	{
		if (i < (size / 2))
		{
			animals[i] = new Dog;
			std::cout << '\n';
		}
		else
		{
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
	unsigned int idx = rand() % BRAIN_CAPACITY;
	Dog dog_a;
	{
		Dog dog_b;
		std::cout << '\n';
		std::cout << "dog #" << dog_a.id << " brain address: " << dog_a.getBrainAddress() << '\n';
		std::cout << "dog #" << dog_a.id << " brain idea: #" << idx << ": " << dog_a.getBrainIdea(idx) << '\n';
		std::cout << "dog #" << dog_b.id << " brain address: " << dog_b.getBrainAddress() << '\n';
		std::cout << "dog #" << dog_b.id << " brain idea: #" << idx << ": " << dog_b.getBrainIdea(idx) << '\n';
		dog_a = dog_b;
	}

	std::cout << '\n';
	std::cout << "dog #" << dog_a.id << " brain address: " << dog_a.getBrainAddress() << '\n';
	std::cout << "dog #" << dog_a.id << " brain idea #" << idx << ": " << dog_a.getBrainIdea(idx) << '\n';
}
