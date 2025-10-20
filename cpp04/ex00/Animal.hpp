#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public :
	Animal();
	~Animal();
	void makeSound();
	std::string getType() const;
	void setType(const std::string& type);

	protected :
	std::string type;

};

class Dog : public Animal
{

};

class Cat : public Animal
{

};

#endif