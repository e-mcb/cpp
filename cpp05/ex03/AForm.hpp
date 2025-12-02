#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
public:
	AForm(const std::string &name, const std::string &target, int signatureGrade, int execGrade);
	virtual ~AForm();
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);

	const std::string& 	getName() const;
	const std::string&	getTarget() const;
	bool				getSignedStatus() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	void				beSigned(const Bureaucrat &b);
	virtual void		execute(Bureaucrat const &executor) const = 0;

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
	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const throw();
	};

private:
	std::string const	name_;
	std::string const	target_;
	bool				signed_;
	int					signGrade_;
	int					execGrade_;

protected:
	void	checkExecutable(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif