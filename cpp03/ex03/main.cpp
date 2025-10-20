#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap diamond("Noob");

    std::cout << std::endl << "=== Testing identity ===" << std::endl;
    diamond.whoAmI();

    std::cout << std::endl << "=== Testing attack ===" << std::endl;
    diamond.attack("Idiot");

    std::cout << std::endl << "=== Taking and repairing damage ===" << std::endl;
    diamond.takeDamage(30);
    diamond.beRepaired(20);

    std::cout << std::endl << "=== Testing inherited ability ===" << std::endl;
    diamond.highFivesGuys();
	diamond.guardGate();

    std::cout << std::endl << "=== End of program ===" << std::endl;
    return 0;
}
