#ifndef DIAMONDTRAPP_HPP
# define DIAMONDTRAPP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public virtual ScavTrap, public virtual FragTrap
{
    public :
    DiamondTrap();
    DiamondTrap(const std::string& name);
    ~DiamondTrap();
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    void whoAmI();

    private :
    std::string Name;
};

#endif
