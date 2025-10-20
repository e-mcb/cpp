#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name),
      FragTrap(name),
      Name(name)
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

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am the DiamondTrap: " << Name << "\nMy ClapTrap name is: "
			  << ClapTrap::Name << std::endl;
}