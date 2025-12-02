#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

Intern::FormType Intern::getFormType(const std::string &name)
{
    if (name == "shrubbery creation")
        return SHRUBBERY;
    else if (name == "robotomy request")
        return ROBOTOMY;
    else if (name == "presidential pardon")
        return PARDON;
    return INVALID;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
    FormType type = getFormType(formName);
    AForm* form = NULL;

    switch (type)
    {
        case SHRUBBERY:
            form = new ShrubberyCreationForm(target);
            break;
        case ROBOTOMY:
            form = new RobotomyRequestForm(target);
            break;
        case PARDON:
            form = new PresidentialPardonForm(target);
            break;
        case INVALID:
        default:
            std::cout << "Intern could not create form: "
                      << formName << " (form does not exist)" << std::endl;
            return NULL;
    }

    std::cout << "Intern creates " << formName << std::endl;
    return form;
}
