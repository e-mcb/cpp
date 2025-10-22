#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
#include "Brain.hpp"

class Animal
{
	public :
	Animal();
	virtual ~Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual void makeSound() const = 0; //makes the class abstract
	std::string getType() const;

	protected :
	std::string Type;

};

class Dog : public Animal
{
	public :
	Dog();
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	void makeSound() const;
	Brain* getBrain() const;

	private :
	Brain* brain;
};

class Cat : public Animal
{
	public :
	Cat();
	~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	void makeSound() const;
	Brain* getBrain() const;

	private :
	Brain* brain;
};

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

class WrongCat : public WrongAnimal
{
	public :
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat& other);
	WrongCat& operator=(const WrongCat& other);
	void makeSound() const;
};

#endif