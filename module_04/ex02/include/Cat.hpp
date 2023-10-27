#ifndef CAT__HPP
#define CAT__HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

public:
	Cat(void);
	Cat(const Cat &obj);
	Cat &operator=(const Cat &obj);
	~Cat(void);

public:
	void makeSound(void) const;
	void deepCopy(const Cat &obj);

public:
	const std::string &getBrainIdea(unsigned int i) const;
	Brain *getBrainAddress(void) const;
};

#endif
