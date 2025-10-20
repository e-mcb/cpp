#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)	:	Name(name),
												HitPoints(10),
												EnergyPoints(10),
												AttackDamage(0)
{
	std::cout << "ClapTrap " << Name << " created!" << std::endl; 
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << Name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (HitPoints <= 0)
	{
		std::cout << "ClapTrap " << Name << " is destroyed and can't attack!" << std::endl;
		return;
	}
	if (EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << Name << " has no energy left to attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << Name << " attacked " << target << " for " 
			  << AttackDamage << " damage!" << std::endl;
	EnergyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= HitPoints)
		HitPoints = 0;
	else
		HitPoints -= amount;

	std::cout << "ClapTrap " << Name << " got hit for " << amount
			  << " HP! Remaining HP: " << HitPoints << std::endl;
	if (HitPoints <= 0)
	{
		std::cout << "Oh no! ClapTrap " << Name
				  << " sustained too much damage and has been destroyed!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (HitPoints <= 0)
	{
		std::cout << "ClapTrap " << Name << " is destroyed and can't repair itself!" << std::endl;
		return ;
	}
	if (EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << Name << " has no energy left to repair itself!" << std::endl;
		return ;
	}
	HitPoints += amount;
	EnergyPoints -= 1;
	std::cout << "ClapTrap " << Name << " healed itself for " 
			  << amount << " HP! Current HP: " << HitPoints << std::endl;
}