#include <string>
class Zombie
{

private:
	std::string name;

public:
	Zombie(std::string arg_name);
	~Zombie(void);
	void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);
