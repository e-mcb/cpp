#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon", target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkExecutable(executor);
	std::cout << getTarget() << " has been pardoned by the Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form)
{
	out << "PresidentialPardonForm: " << form.getName()
		<< ", Sign Grade: " << form.getSignGrade()
		<< ", Exec Grade: " << form.getExecGrade()
		<< ", Signed: " << (form.getSignedStatus() ? "Yes" : "No")
		<< ", Target: " << form.getTarget();
	return out;
}
