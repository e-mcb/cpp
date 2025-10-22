#include "Animal.hpp"

int main()
{
	std::cout << "=== Creating Dog1 ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "Chase the mailman");
	dog1.getBrain()->setIdea(1, "Eat bone");
	std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog1 idea[1]: " << dog1.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	Dog dog2 = dog1;
	std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea[1]: " << dog2.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	dog1.getBrain()->setIdea(1, "Bury bone");
	std::cout << "Dog1 idea[1]: " << dog1.getBrain()->getIdea(1) << std::endl;
	std::cout << "Dog2 idea[1] (should be unchanged): " << dog2.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	Cat cat1;
	cat1.getBrain()->setIdea(0, "Climb curtains");
	cat1.getBrain()->setIdea(1, "Ignore humans");
	std::cout << std::endl;

	Cat cat2;
	cat2 = cat1;
	std::cout << "Cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	cat1.getBrain()->setIdea(0, "Knock over glass");
	std::cout << "Cat1 idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 idea[0]: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "Dog1 is a " << dog1.getType() << " and says: ";
	dog1.makeSound();
	std::cout << "Cat1 is a " << cat1.getType() << " and says: ";
	cat1.makeSound();
	std::cout << std::endl;

	const int size = 100;
	Animal* animals[size];
	for (int i = 0; i < size; ++i)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;

	for (int i = 0; i < size; ++i)
	{
		std::cout << "Animal " << i << " (" << animals[i]->getType() << ") says: ";
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	for (int i = 0; i < size; ++i) 
	{
		delete animals[i];
	}
	return 0;
}
