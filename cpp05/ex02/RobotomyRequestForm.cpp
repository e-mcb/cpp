#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request", target,  72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkExecutable(executor);

	srand(time(NULL));

	std::cout << "* infernal drilling noises *" << std::endl;

	if (rand() % 2)
	std::cout << AForm::getTarget() << " has been robotomized successfully!" << std::endl;
	else
	std::cout << "The robotomy failed." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
	out << "RobotomyRequestForm: " << form.getName()
		<< ", Sign Grade: " << form.getSignGrade()
		<< ", Exec Grade: " << form.getExecGrade()
		<< ", Signed: " << (form.getSignedStatus() ? "Yes" : "No")
		<< ", Target: " << form.AForm::getTarget();
	return (out);
}