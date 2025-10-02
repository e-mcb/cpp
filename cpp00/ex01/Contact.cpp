#include "Contact.hpp"

Contact::Contact() 
{
	std::cout << GREEN << "Contact created" << RESET << std::endl;
}

Contact::~Contact() 
{
	std::cout << RED << "Contact destroyed" << RESET << std::endl;
}

void Contact::setFirstName(const std::string &fn) 
{
	firstName = fn;
}

std::string Contact::getFirstName() const 
{
	return firstName;
}

void Contact::setLastName(const std::string &ln) 
{
	lastName = ln;
}

std::string Contact::getLastName() const 
{
	return lastName;
}

void Contact::setNickname(const std::string &nn)
{
	nickname = nn;
}

std::string Contact::getNickname() const 
{
	return nickname;
}

void Contact::setPhoneNumber(const std::string &pn) 
{
	phoneNumber = pn;
}

std::string Contact::getPhoneNumber() const 
{
	return phoneNumber;
}

void Contact::setDarkestSecret(const std::string &ds) 
{
	darkestSecret = ds;
}

std::string Contact::getDarkestSecret() const 
{
	return darkestSecret;
}
