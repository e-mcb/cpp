#include "Animal.hpp"

Cat::Cat()
{
	Type = "Cat";
	std::cout << "A new Cat has been instancied" << std::endl;
}

Cat::~Cat()
{
	std::cout << "The instance for the cat has been destroyed" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called\n";
    Type = other.Type;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Dog assignment operator called\n";
    if (this != &other)
	{
        Animal::operator=(other);
        Type = other.Type;
    }
    return *this;
}

void Cat::makeSound() const
{
	std::cout << "The cat says: \"Meow\"" << std::endl;
}

