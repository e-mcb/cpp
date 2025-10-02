#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

void display_header() {
	std::cout << std::setw(10) << "Index" << "|"
	          << std::setw(10) << "First Name" << "|"
	          << std::setw(10) << "Last Name" << "|"
	          << std::setw(10) << "Nickname" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

std::string truncate(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

int main() 
{
	PhoneBook phoneBook;
	std::string command;

	while (true) 
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nEnd of input detected. Exiting." << std::endl;
			break;
		}
		if (command == "EXIT")
		{
			break;
		} 
		else if (command == "ADD") 
		{
			Contact c;
			std::string input;

			std::cout << "Enter first name: ";
			std::getline(std::cin, input);
			c.setFirstName(input);

			std::cout << "Enter last name: ";
			std::getline(std::cin, input);
			c.setLastName(input);

			std::cout << "Enter nickname: ";
			std::getline(std::cin, input);
			c.setNickname(input);

			std::cout << "Enter phone number: ";
			std::getline(std::cin, input);
			c.setPhoneNumber(input);

			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, input);
			c.setDarkestSecret(input);

			phoneBook.addContact(c);
			std::cout << "Contact added!" << std::endl;

		}
		else if (command == "SEARCH") 
		{
			display_header();
			for (int i = 0; i < 8; i++) {
				Contact c = phoneBook.getContact(i);
				if (c.getFirstName().empty()) continue;

				std::cout << std::setw(10) << i << "|"
				          << std::setw(10) << truncate(c.getFirstName()) << "|"
				          << std::setw(10) << truncate(c.getLastName()) << "|"
				          << std::setw(10) << truncate(c.getNickname()) << std::endl;
			}

			std::cout << "Enter index to view full contact: ";
			std::string idxStr;
			std::getline(std::cin, idxStr);

			try 
			{
				int index = std::stoi(idxStr);
				if (index < 0 || index > 7 || phoneBook.getContact(index).getFirstName().empty()) 
				{
					std::cout << "Invalid index or contact does not exist." << std::endl;
				} else 
				{
					phoneBook.displayContact(index);
				}

			} 
			catch (...) 
			{
				std::cout << "Invalid input. Please enter a number between 0 and 7." << std::endl;
			}
		} 
		else 
		{
			std::cout << "Unknown command. Try ADD, SEARCH, or EXIT." << std::endl;
		}
	}

	std::cout << "Exiting phonebook." << std::endl;
	return 0;
}
