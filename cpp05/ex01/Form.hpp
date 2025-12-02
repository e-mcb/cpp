#ifndef Form_HPP
#define Form_HPP

#include <iostream>

class Bureaucrat;

class Form
{
public:
	Form(const std::string &name, int signatureGrade, int execGrade);
	~Form();
	Form(const Form& other);
	Form& operator=(const Form& other);

	const std::string& 	getName() const;
	bool			getSignedStatus() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	void				beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

private:
	std::string const	name_;
	bool				signed_;
	int					signGrade_;
	int					execGrade_;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif