#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << "--- Initial Forms ---" << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        try { shrub.beSigned(bob); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
        try { robot.beSigned(bob); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
        try { pardon.beSigned(bob); } catch (std::exception &e) { std::cout << e.what() << std::endl; }

        shrub.beSigned(alice);
        robot.beSigned(alice);
        pardon.beSigned(alice);

        std::cout << "\n--- After Signing ---" << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        bob.executeForm(shrub);
        bob.executeForm(robot);
        bob.executeForm(pardon);

        std::cout << "\n--- Alice Executes ---" << std::endl;
        alice.executeForm(shrub);
        alice.executeForm(robot);
        alice.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
