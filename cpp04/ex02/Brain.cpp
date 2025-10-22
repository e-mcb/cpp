#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; ++i)
		ideas[i] = "Empty idea";
	std::cout << "A new Brain has been created. It is currently empty, time to start filling it" << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
	{
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
	std::cout << "The Brain has been destroyed, you've created a redditor" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
    else
        std::cout << "Invalid idea index!\n";
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "[Invalid index]";
}