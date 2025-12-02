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

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    HitPoints = other.HitPoints;
    EnergyPoints = other.EnergyPoints;
    AttackDamage = other.AttackDamage;
    std::cout << "FragTrap " << Name << " copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    std::cout << "FragTrap " << Name << " assigned!" << std::endl;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " requests a high five!" << std::endl;
    std::cout << "Do you want to high five? (y/n): ";

    char response;
    std::cin >> response;

    if (response == 'y')
        std::cout << "High five accepted!" << std::endl;
    else if (response == 'n')
        std::cout << "High five declined.​" << std::endl;
	else
		std::cout << "FragTrap " << Name << " looks at you like an idiot.​" << std::endl;
}
