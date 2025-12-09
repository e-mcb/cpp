#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
{
	Type = "Dog";
	std::cout << "A new Dog has been instancied" << std::endl;
}

Dog::~Dog()
{
	std::cout << "The instance for the dog has been destroyed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog copy constructor called\n";
    Type = other.Type;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator called\n";
    if (this != &other)
	{
        Animal::operator=(other);
        Type = other.Type;
    }
    return *this;
}

void Dog::makeSound() const
{
	std::cout << "The dog says:\"Bark bark\"" << std::endl;
}