#include <iomanip>
#include <cstring>
#include <unistd.h>
#include "PhoneBook.hpp"

void display_header()
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}

std::string sanitizeInput(const std::string& str)
{
    std::string result = str;
    for (size_t i = 0; i < result.length(); ++i)
    {
        if (result[i] == '\t')
            result[i] = ' ';
    }
    return result;
}


std::string truncate(const std::string& str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

std::string to_string(int value)
{
    std::ostringstream oss;
    oss << value;
    return (oss.str());
}

void printBanner()
{
    std::cout << "\033[38;5;205m";
    std::cout << " __        __   _                                     \n";
    std::cout << " \\ \\      / /__| | ___ ___  _ __ ___   ___           \n";
    std::cout << "  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\        \n";
    std::cout << "   \\ V  V /  __/ | (_| (_) | | | | | |  __/           \n";
    std::cout << "    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|        \n";
    std::cout << "           | |_ ___   | |_| |__   ___                 \n";
    std::cout << "           | __/ _ \\  | __| '_ \\ / _ \\              \n";
    std::cout << "           | || (_) | | |_| | | |  __/               \n";
    std::cout << "  ____  _   \\__\\___/   \\__|_| |_|\\___|           _  \n";
    std::cout << " |  _ \\| |__   ___  _ __   ___| |__   ___   ___ | | __\n";
    std::cout << " | |_) | '_ \\ / _ \\| '_ \\ / _ \\ '_ \\ / _ \\ / _ \\| |/ /\n";
    std::cout << " |  __/| | | | (_) | | | |  __/ |_) | (_) | (_) |   < \n";
    std::cout << " |_|   |_| |_|\\___/|_| |_|\\___|_.__/ \\___/ \\___/|_|\\_\\\n";
    std::cout << "\033[0m";
}

void fillPhoneBook(PhoneBook &phoneBook)
{
    std::cout << "\033[1;33mPhonebook filled from --fill flag\033[0m" << std::endl;

    for (int i = 0; i < 8; ++i)
    {
        Contact c;
        std::stringstream ss;

        ss << "FirstName" << (i + 1);
        c.setFirstName(ss.str());
        ss.str("");
        ss.clear();

        ss << "LastName" << (i + 1);
        c.setLastName(ss.str());
        ss.str("");
        ss.clear();

        ss << "Nickname" << (i + 1);
        c.setNickname(ss.str());
        ss.str("");
        ss.clear();

        ss << (i + 1);
        c.setPhoneNumber(ss.str());
        ss.str("");
        ss.clear();

        ss << "Secret" << (i + 1);
        c.setDarkestSecret(ss.str());

        phoneBook.addContact(c);
    }
}

bool isNumeric(const std::string& str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
        {
            return false;
        }
    }
    return true;
}


void addContactInteraction(PhoneBook &phoneBook)
{
    std::string input;
    Contact c;

    do
    {
        std::cout << "\033[1;36mEnter first name: \033[0m";
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "\033[1;31mFirst name cannot be empty.\033[0m\n";
        }
    }
    while (input.empty());
    c.setFirstName(input);

    do
    {
        std::cout << "\033[1;36mEnter last name: \033[0m";
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "\033[1;31mLast name cannot be empty.\033[0m\n";
        }
    }
    while (input.empty());
    c.setLastName(input);

    do
    {
        std::cout << "\033[1;36mEnter nickname: \033[0m";
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "\033[1;31mNickname cannot be empty.\033[0m\n";
        }
    }
    while (input.empty());
    c.setNickname(input);

    do
    {
        std::cout << "\033[1;36mEnter phone number (digits only): \033[0m";
        std::getline(std::cin, input);
        if (!isNumeric(input))
        {
            std::cout << "\033[1;31mPhone number must contain digits only and cannot be empty.\033[0m\n";
        }
    }
    while (!isNumeric(input));
    c.setPhoneNumber(input);

    do
    {
        std::cout << "\033[1;36mEnter darkest secret: \033[0m";
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << "\033[1;31mDarkest secret cannot be empty.\033[0m\n";
        }
    }
    while (input.empty());
    c.setDarkestSecret(input);

    phoneBook.addContact(c);
    std::cout << "Contact added!" << std::endl;
}


void searchInteraction(const PhoneBook &phoneBook)
{
    display_header();

    for (int i = 0; i < 8; i++)
    {
        Contact c = phoneBook.getContact(i);
        if (c.getFirstName().empty())
            continue;
		
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << truncate(sanitizeInput(c.getFirstName())) << "|"
				<< std::setw(10) << truncate(sanitizeInput(c.getLastName())) << "|"
				<< std::setw(10) << truncate(sanitizeInput(c.getNickname())) << std::endl;

    }

    std::cout << "\033[1;36mEnter index to view full contact: \033[0m";

    std::string idxStr;
    std::getline(std::cin, idxStr);
    std::stringstream to_int(idxStr);
    int index;

    if (!(to_int >> index))
    {
        std::cerr << "Invalid Input: Not a numeric value" << std::endl;
    }
    else if (index < 0 || index > 7)
    {
        std::cerr << "Invalid index" << std::endl;
    }
    else if (phoneBook.getContact(index).getFirstName().empty())
    {
        std::cerr << "Contact does not exist" << std::endl;
    }
    else
    {
        phoneBook.displayContact(index);
    }
}

void mainLoop(PhoneBook &phoneBook)
{
    std::string command;

    while (true)
    {
        std::cout << "\033[1;36mEnter command (ADD, SEARCH, EXIT): \033[0m";
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
            addContactInteraction(phoneBook);
        }
        else if (command == "SEARCH")
        {
            searchInteraction(phoneBook);
        }
        else
        {
            std::cout << "Unknown command. Try ADD, SEARCH, or EXIT." << std::endl;
        }
    }
}


int main(int argc, char *argv[])
{
    printBanner();

    PhoneBook phoneBook;

    if (argc > 1 && std::strcmp(argv[1], "--fill") == 0)
    {
        fillPhoneBook(phoneBook);
    }

    mainLoop(phoneBook);

	std::cout << "Goodbye!" << std::endl;
    return (0);
}
