#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "A new animal has been instancied" << std::endl;
}

Animal::~Animal()
{
	std::cout << "The instance for the animal has been destroyed" << std::endl;
}

Animal::Animal(const Animal& other) : Type(other.Type)
{
    std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called\n";
    if (this != &other)
	{
        Type = other.Type;
    }
    return *this;
}

std::string Animal::getType() const
{
	return (Type);
}

void Animal::makeSound() const
{
	std::cout << "The animal makes a sound" << std::endl;
}


