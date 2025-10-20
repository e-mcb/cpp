#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	public :
	ClapTrap(const std::string &name);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	protected : //update the variables of ClapTrap to protected so ScavTrap can access them
	std::string 	Name;
	unsigned int	HitPoints;
	unsigned int	EnergyPoints;
	unsigned int	AttackDamage;
};

#endif