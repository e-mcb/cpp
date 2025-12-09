#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal(); // Instanciation tests
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl; // getter tests
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound(); //makeSound tests
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	const WrongAnimal* fake = new WrongAnimal(); //Wrong class instanciation tests
	const WrongAnimal* fakecat = new WrongCat();
	std::cout << std::endl;
	
	std::cout << fake->getType() << " " << std::endl; //Wrong class getter tests
	std::cout << fakecat->getType() << " " << std::endl;
	std::cout << std::endl;
	
	fake->makeSound(); //Wrong class sound tests
	fakecat->makeSound();
	std::cout << std::endl;

	const Animal* ptr; //Can use a pointer to the base class on a derived class
					   //The opposite is however not true
	ptr = j;
	ptr->makeSound();
	std::cout << std::endl;

	//const Cat* catptr = meta; this doesnt work (Every cat are animals but not every animals are cats)
	
	
	delete (meta); //Memory cleanup
	delete (j);
	delete (i);
	delete (fake);
	delete (fakecat); 
	return 0;
}