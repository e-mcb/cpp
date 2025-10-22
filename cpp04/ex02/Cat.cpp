#include "Animal.hpp"

Cat::Cat()
{
	Type = "Cat";
	brain = new Brain();
	std::cout << "A new Cat has been instancied" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "The instance for the cat has been destroyed" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called\n";
	brain = new Brain(*other.brain);
    Type = other.Type;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment operator called\n";
    if (this != &other)
	{
        Animal::operator=(other);
        Type = other.Type;
		delete brain;
		brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const
{
	std::cout << "The cat says: \"Meow\"" << std::endl;
}

Brain* Cat::getBrain() const
{
    return brain;
}


