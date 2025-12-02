#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("Noob");

	diamond.whoAmI();

	diamond.attack("Idiot");

	diamond.takeDamage(30);
	diamond.beRepaired(20);

	diamond.highFivesGuys();
	diamond.guardGate();

	return 0;
}
