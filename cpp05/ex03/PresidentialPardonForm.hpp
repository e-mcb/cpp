#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string &target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	void		execute(Bureaucrat const &executor) const;
};
std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &ppf);

#endif