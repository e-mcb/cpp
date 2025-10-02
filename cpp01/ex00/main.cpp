#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() 
{
    Zombie* heapZombie = newZombie("Heap allocated zombie");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Stack allocated zombie");
	randomChump("Idiot");

    return 0;
}