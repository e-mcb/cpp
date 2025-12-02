#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string& stringREF = str;
    std::string* stringPTR = &str;

    const std::string green = "\033[32m";
    const std::string red = "\033[31m";
    const std::string blue = "\033[34m";
    const std::string reset = "\033[0m";

    std::cout << green << "Address of str: " << &str << reset << std::endl;
    std::cout << red << "Address held by stringPTR: " << stringPTR << reset << std::endl;
    std::cout << blue << "Address held by stringREF: " << &stringREF << reset << std::endl;

    std::cout << green << "Value of str: " << str << reset << std::endl;
    std::cout << red << "Value pointed to by stringPTR: " << *stringPTR << reset << std::endl;
    std::cout << blue << "Value pointed to by stringREF: " << stringREF << reset << std::endl;


	std::cout << "\n_______________________________________________________\n" << std::endl;

	std::cout << green << "Original value of str: " << str << reset << std::endl;


    *stringPTR = "Modified via pointer";
    std::cout << red << "After modification through pointer, str: " << str << reset << std::endl;

    stringREF = "Modified via reference";
    std::cout << blue << "After modification through reference, str: " << str << reset << std::endl;

    std::cout << "\nAddresses:" << std::endl;
    std::cout << green << "Address of str: " << &str << reset << std::endl;
    std::cout << red << "Address held by stringPTR: " << stringPTR << reset << std::endl;
    std::cout << blue << "Address held by stringREF: " << &stringREF << reset << std::endl;
}
