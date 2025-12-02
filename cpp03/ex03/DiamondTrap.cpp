#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name"), ScavTrap("default_name"), FragTrap("default_name"), Name("default")
{
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;

    std::cout << "DiamondTrap default constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), Name(name)
{
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;

    std::cout << "DiamondTrap " << Name << " constructed!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << Name << " destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), Name(other.Name)
{
    HitPoints = other.HitPoints;
    EnergyPoints = other.EnergyPoints;
    AttackDamage = other.AttackDamage;
    std::cout << "DiamondTrap " << Name << " copied!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        Name = other.Name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    std::cout << "DiamondTrap " << Name << " assigned!" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am the DiamondTrap: " << Name << "\nMy ClapTrap name is: "
              << ClapTrap::Name << std::endl;
}
