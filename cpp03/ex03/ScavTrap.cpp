#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap default constructed!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
{
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << Name << " constructed!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << Name << " destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	HitPoints = other.HitPoints;
	EnergyPoints = other.EnergyPoints;
	AttackDamage = other.AttackDamage;
	std::cout << "ScavTrap " << Name << " copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
		HitPoints = other.HitPoints;
		EnergyPoints = other.EnergyPoints;
		AttackDamage = other.AttackDamage;
	}
	std::cout << "ScavTrap " << Name << " assigned!" << std::endl;
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << Name << " is now in Gate Keeper mode! (It doesn't do anything)" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (HitPoints <= 0) {
		std::cout << "ScavTrap " << Name << " is destroyed and can't attack!" << std::endl;
		return;
	}
	if (EnergyPoints <= 0) {
		std::cout << "ScavTrap " << Name << " has no energy left to attack!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << Name << " attacked " << target << " for " << AttackDamage << " damage!" << std::endl;
	EnergyPoints -= 1;
}
