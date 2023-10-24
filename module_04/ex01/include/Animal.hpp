#ifndef ANIMAL__HPP
#define ANIMAL__HPP
#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal &obj);
	Animal &operator=(const Animal &obj);
	virtual ~Animal(void);

public:
	const std::string &getType(void) const;

public:
	virtual void makeSound(void) const;

	// public:
	// 	void deepCopy()
};

#endif
