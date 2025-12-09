#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include "Animal.hpp"

class Animal;

class WrongAnimal
{
	public :
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	virtual void makeSound() const;
	std::string getType() const;

	protected:
	std::string Type;
};

#endif