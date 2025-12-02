#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    Intern intern;
    Bureaucrat alice("Alice", 1);

    AForm* shrub = intern.makeForm("shrubbery creation", "home");
    AForm* robot = intern.makeForm("robotomy request", "Bender");
    AForm* pardon = intern.makeForm("presidential pardon", "Marvin");
    AForm* bad = intern.makeForm("unknown form", "nobody");

    std::cout << std::endl;

    if (shrub)
    {
        alice.signForm(*shrub);
        alice.executeForm(*shrub);
    }

    if (robot)
    {
        alice.signForm(*robot);
        alice.executeForm(*robot);
    }

    if (pardon)
    {
        alice.signForm(*pardon);
        alice.executeForm(*pardon);
    }

    delete shrub;
    delete robot;
    delete pardon;
    delete bad;

    return 0;
}
