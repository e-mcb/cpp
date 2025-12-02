#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int signatureGrade, int execGrade)
	: name_(name),
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

Form::Form(const Form &other)
	: name_(other.name_),
	signed_(other.signed_),
	signGrade_(other.signGrade_),
	execGrade_(other.execGrade_)
{}

Form::~Form() {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->signed_ = other.signed_;
	}
	return *this;
}

const std::string &Form::getName() const
{
	return name_;
}

bool Form::getSignedStatus() const
{
	return signed_;
}

int Form::getSignGrade() const
{
	return signGrade_;
}

int Form::getExecGrade() const
{
	return execGrade_;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > signGrade_)
	{
		throw GradeTooLowException();
	}
	signed_ = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form \"" << form.getName() << "\" "
		<< "(Sign grade: " << form.getSignGrade()
		<< ", Exec grade: " << form.getExecGrade()
		<< ", Signed: " << (form.getSignedStatus() ? "Yes" : "No")
		<< ")";
	return out;
}
