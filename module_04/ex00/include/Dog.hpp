#ifndef DOG__HPP
#define DOG__HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &obj);
	Dog &operator=(const Dog &obj);
	~Dog(void);

public:
	void makeSound(void) const;
};

#endif
