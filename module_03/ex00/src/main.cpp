#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap t("Geza");

	t.attack("Pityu");
	t.takeDamage(5);
	t.beRepaired(5);
	t.beRepaired(10);
	t.beRepaired(10);

	return EXIT_SUCCESS;
}
