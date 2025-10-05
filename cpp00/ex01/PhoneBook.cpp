#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact &c) 
{
	if (count < 8) 
	{
		contacts[count] = c;
		count++;
	} 
	else 
	{
		contacts[oldestIndex] = c;
		oldestIndex = (oldestIndex + 1) % 8;
	}
}

void PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= count) 
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	Contact c = contacts[index];
	std::cout << "First Name: " << c.getFirstName() << std::endl;
	std::cout << "Last Name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}

Contact PhoneBook::getContact(int index) const
{
	if (index < 0 || index >= 8) 
	{
		return Contact();
	}
	return contacts[index];
}
