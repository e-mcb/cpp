#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
/*
	Definition of the PhoneBook class
	The function declarations and definitions are in PhoneBook.cpp
	The function sharing the name of the class is the constructor
	The function sharing the name of the class and preceded by a tilde is the destructor
	The constructor is called when an instance of the class is created
	The destructor is called when an instance of the class is destroyed (When it goes out of scope
	or when the program ends)
*/
class PhoneBook
{
	public:
		PhoneBook(void); // Constructor
		~PhoneBook(void); // Destructor
		void addContact(const Contact &c); // Add a contact to the phone book
		void displayContact(int index); // Display a specific contact by index
		Contact getContact(int index) const;

	
	private:
		Contact contacts[8]; // Array of 8 Contact instances
		int count = 0; // Number of contacts added to the phone book
		int oldestIndex = 0; // Index of the oldest contact to be replaced

};

#endif