#ifndef DOG__HPP
#define DOG__HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog(void);
	Dog(const Dog &obj);
	Dog &operator=(const Dog &obj);
	~Dog(void);

public:
	void makeSound(void) const;
	void deepCopy(const Dog &obj);
};

#endif
