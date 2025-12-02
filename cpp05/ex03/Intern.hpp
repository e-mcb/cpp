#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();
    AForm* makeForm(const std::string &formName, const std::string &target) const;

private:
    enum FormType
    {
        SHRUBBERY,
        ROBOTOMY,
        PARDON,
        INVALID
    };
	static FormType getFormType(const std::string &name);
};

#endif
