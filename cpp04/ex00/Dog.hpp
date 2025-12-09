#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"

class Animal;

class Dog : public Animal
{
	public :
	Dog();
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	void makeSound() const;
};

#endif