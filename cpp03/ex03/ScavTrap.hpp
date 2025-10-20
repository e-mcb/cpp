#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap //added the virtual keyword in order to prevent the diamond problem
{
	public :
	ScavTrap(const std::string& name);
	~ScavTrap();
	void guardGate();
	void attack(const std::string& target);
};

#endif