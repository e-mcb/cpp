#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap scav("Idiot");
	ScavTrap vacs("Noob");

	std::cout << std::endl;

	scav.attack("Noob");
	vacs.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();
	scav.takeDamage(200);
	scav.attack("Stupid");

	std::cout << "\nBase class attack method, attack message will print \"ClapTrap\"" << std::endl;

	scav.ClapTrap::attack("Not smart");

	std::cout << std::endl;
	
	return (0);
}
