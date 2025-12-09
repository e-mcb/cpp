#ifndef Cat_HPP
# define Cat_HPP

# include "Animal.hpp"

class Animal;

class Cat : public Animal
{
	public :
	Cat();
	~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	void makeSound() const;
};

#endif