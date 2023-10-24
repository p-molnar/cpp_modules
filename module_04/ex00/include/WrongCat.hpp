#ifndef WRONGCAT__HPP
#define WRONGCAT__HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat &obj);
	WrongCat &operator=(const WrongCat &obj);
	~WrongCat(void);

public:
	void makeSound(void) const;
};

#endif
