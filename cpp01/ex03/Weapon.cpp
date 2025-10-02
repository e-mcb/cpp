#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "\033[32mA new weapon of type " << _type << " has been created!\033[0m" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "\033[31mWeapon of type " << _type << " has been destroyed!\033[0m" << std::endl;
}

const std::string& Weapon::getType() const
{
	return _type;
}

void Weapon::setType(std::string type)
{
	std::cout << "\033[33mChanging weapon type from " << this->_type 
	          << " to " << type << "\033[0m" << std::endl;
	this->_type = type;
}