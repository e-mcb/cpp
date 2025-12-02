#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name), grade_(grade)
{
    if (grade_ < 1)
        throw GradeTooHighException();
    if (grade_ > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_), grade_(other.grade_) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        grade_ = other.grade_;
    return *this;
}

std::string Bureaucrat::getName() const
{
	return (this->name_);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade_);
}

void	Bureaucrat::promotion()
{
	if (grade_ <= 1)
		throw GradeTooHighException();
	grade_--;
}

void	Bureaucrat::demotion()
{
	if (grade_ >= 150)
		throw GradeTooLowException();
	grade_++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Bureaucrat grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}

