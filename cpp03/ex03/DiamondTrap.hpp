#ifndef DIAMONDTRAPP_HPP
# define DIAMONDTRAPP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public :
	DiamondTrap(const std::string& name);
	~DiamondTrap();
	void	whoAmI();
	void	attack(const std::string& target);

	private :
	std::string Name;
};

#endif