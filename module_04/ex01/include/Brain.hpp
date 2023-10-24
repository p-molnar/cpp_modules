#ifndef BRAIN__HPP
#define BRAIN__HPP

#include <string>

#define SIZE 100

class Brain
{
protected:
	std::string ideas[SIZE];

public:
	Brain(void);
	Brain(const Brain &obj);
	Brain &operator=(const Brain &obj);
	~Brain(void);
};

#endif
