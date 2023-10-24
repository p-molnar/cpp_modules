#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	std::cout << "cat makes sound: ";
	cat->makeSound();
	std::cout << "dog makes sound: ";
	dog->makeSound();
	std::cout << "animal makes sound: ";
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;

	const WrongAnimal *wrong_meta = new WrongAnimal();
	const WrongAnimal *wrong_cat = new WrongCat();

	std::cout << wrong_cat->getType() << " " << std::endl;

	std::cout << "wrong cat makes sound: ";
	wrong_cat->makeSound();
	std::cout << "wrong animal makes sound: ";
	wrong_meta->makeSound();
	delete wrong_meta;
	delete wrong_cat;
	return EXIT_SUCCESS;
}
