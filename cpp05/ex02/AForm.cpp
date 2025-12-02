#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name,
							   const std::string &target,
							   int signatureGrade,
							   int execGrade)
	: name_(name),
	target_(target),
	signed_(false),
	signGrade_(signatureGrade),
	execGrade_(execGrade)
	
{
	if (signGrade_ < 1 || execGrade_ < 1)
	{
		throw GradeTooHighException();
	}
	if (signGrade_ > 150 || execGrade_ > 150)
	{
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm &other)
	: name_(other.name_),
	signed_(other.signed_),
	signGrade_(other.signGrade_),
	execGrade_(other.execGrade_)
{}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->signed_ = other.signed_;
	}
	return *this;
}

const std::string &AForm::getName() const
{
	return name_;
}

const std::string &AForm::getTarget() const
{
	return target_;
}

bool AForm::getSignedStatus() const
{
	return signed_;
}

int AForm::getSignGrade() const
{
	return signGrade_;
}

int AForm::getExecGrade() const
{
	return execGrade_;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > signGrade_)
	{
		throw GradeTooLowException();
	}
	signed_ = true;
}

void	AForm::checkExecutable(Bureaucrat const &executor) const
{
	if (executor.getGrade() > execGrade_)
	{
		throw GradeTooLowException();
	}
	if (!signed_)
	{
		throw FormNotSignedException();
	}
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form hasnt been signed yet.";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form \"" << form.getName() << "\" "
		<< "(Sign grade: " << form.getSignGrade()
		<< ", Exec grade: " << form.getExecGrade()
		<< ", Signed: " << (form.getSignedStatus() ? "Yes" : "No")
		<< ")";
	return out;
}
