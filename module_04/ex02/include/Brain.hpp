#ifndef BRAIN__HPP
#define BRAIN__HPP

#include <string>
#define BRAIN_CAPACITY 100

class Brain
{
public:
	std::string ideas[BRAIN_CAPACITY];

public:
	Brain(void);
	Brain(const Brain *obj);
	Brain(const Brain &obj);
	Brain &operator=(const Brain &obj);
	~Brain(void);
};

#endif
