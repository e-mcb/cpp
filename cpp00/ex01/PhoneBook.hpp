#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <sstream>
# include <iostream>
# include <iomanip>
# include <cstring>
# include <unistd.h>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void addContact(const Contact &c);
		void displayContact(int index) const;
		Contact getContact(int index) const;

	
	private:
		Contact contacts[8];
		int count;
		int oldestIndex;

};

#endif