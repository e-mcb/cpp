#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 150);
        Bureaucrat b3("Charlie", 75);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;

        b3.promotion();
        std::cout << b3 << std::endl;

        b3.demotion();
        std::cout << b3 << std::endl;

        b1.promotion();
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b4("Dave", 0);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught while creating Dave: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b5("Eve", 151);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught while creating Eve: " << e.what() << std::endl;
    }

    return 0;
}
