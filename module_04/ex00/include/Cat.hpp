#ifndef CAT__HPP
#define CAT__HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &obj);
	Cat &operator=(const Cat &obj);
	~Cat(void);

public:
	void makeSound(void) const;
};

#endif
