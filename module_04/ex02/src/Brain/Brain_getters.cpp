#include "Brain.hpp"
#include <string>

const std::string &Brain::getIdea(unsigned int i) const
{
	return ideas[i];
}
