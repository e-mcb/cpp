#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a("Idiot");
	ClapTrap	b("Stupid");

	std::cout << std::endl;

	a.attack("Stupid");
	b.takeDamage(0);

	std::cout << std::endl;

	a.beRepaired(2);

	std::cout << std::endl;

	for (int i = 0; i < 10; ++i)
		a.attack("Dummy");

	std::cout << std::endl;

	a.attack("Ghost");

	std::cout << std::endl;

	b.takeDamage(100);
	b.attack("Idiot");
	b.beRepaired(5);

	std::cout << std::endl;
	return (0);
}
