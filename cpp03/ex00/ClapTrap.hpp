#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	public :
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap &operator=(const ClapTrap &other);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	private :
	std::string 	Name;
	unsigned int	HitPoints;
	unsigned int	EnergyPoints;
	unsigned int	AttackDamage;
};

#endif