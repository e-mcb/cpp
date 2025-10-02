#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "\033[32mA new zombie named " << _name << " has been created!\033[0m" << std::endl;
}

Zombie::Zombie (void) : _name("Unnamed")
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

void Zombie::setName(std::string name)
{
	std::cout << "\033[33mChanging zombie name from " << this->_name 
	          << " to " << name << "\033[0m" << std::endl;
	this->_name = name;
}
