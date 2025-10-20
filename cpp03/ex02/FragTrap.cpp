#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;

    std::cout << "FragTrap " << Name << " constructed!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << Name << " destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " requests a high five! ✋" << std::endl;
    std::cout << "Do you want to high five? (y/n): ";

    char response;
    std::cin >> response;

    if (response == 'y' || response == 'Y')
        std::cout << "High five accepted! ✋😁" << std::endl;
    else
        std::cout << "High five declined. 😞🤦‍♂️​" << std::endl;
}

