#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "\033[32mA new zombie named " << _name << " has been created!\033[0m" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "\033[31mZombie " << _name << " has been destroyed!\033[0m" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << "\033[34m" << this->_name << ": BraiiiiiiinnnzzzZ...\033[0m" << std::endl;
}