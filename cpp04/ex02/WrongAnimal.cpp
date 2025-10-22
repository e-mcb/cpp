#include "Animal.hpp"

WrongAnimal::WrongAnimal()
{
	Type = "Animal..?";
	std::cout << "A new... Animal...? has been created... I think?" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Phew, the fake animal has been destroyed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : Type(other.Type)
{
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assignment operator called\n";
    if (this != &other)
	{
        Type = other.Type;
    }
    return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "The weird thing makes some sort of sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (Type);
}

WrongCat::WrongCat()
{
	Type = "Definitely not a Cat";
	std::cout << "Something that does not look like a cat has been instancied" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Phew, the fake cat has been destroyed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment operator called\n";
    if (this != &other)
	{
        Type = other.Type;
    }
    return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "The \"Cat\" says \"Mooooo\"" << std::endl;
}