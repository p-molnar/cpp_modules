#ifndef WRONGANIMAL__HPP
#define WRONGANIMAL__HPP
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &obj);
	WrongAnimal &operator=(const WrongAnimal &obj);
	~WrongAnimal(void);

public:
	const std::string &getType(void) const;

public:
	void makeSound(void) const;
};

#endif
