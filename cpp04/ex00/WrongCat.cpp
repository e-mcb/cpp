#include "WrongCat.hpp"

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