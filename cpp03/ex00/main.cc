#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Idiot");
    ClapTrap b("Stupid");

    std::cout << std::endl;

    // Attack & Damage
    a.attack("Stupid");
    b.takeDamage(0); // 0 For consistency sake with the attack value. Can be modified

    std::cout << std::endl;

    // Idiot repairs itslef
    a.beRepaired(2);

    std::cout << std::endl;

    // Stam drain Idiot
    for (int i = 0; i < 10; ++i)
        a.attack("Dummy");

    std::cout << std::endl;

    // Idiot tries to attack with no stam
    a.attack("Ghost");

    std::cout << std::endl;

    // kill Stupid
    b.takeDamage(100);
    b.attack("Idiot");
    b.beRepaired(5);

    std::cout << std::endl;
    return (0);
}
