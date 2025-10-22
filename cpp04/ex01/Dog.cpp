#include "Animal.hpp"

Dog::Dog()
{
	Type = "Dog";
	brain = new Brain();
	std::cout << "A new Dog has been instancied" << std::endl;
}

Dog::~Dog()
{
	delete (brain);
	std::cout << "The instance for the dog has been destroyed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog copy constructor called\n";
	brain = new Brain(*other.brain);
    Type = other.Type;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator called\n";
    if (this != &other)
	{
        Animal::operator=(other);
        Type = other.Type;
		delete (brain);
		brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const
{
	std::cout << "The dog says:\"Bark bark\"" << std::endl;
}

Brain* Dog::getBrain() const
{
    return brain;
}
