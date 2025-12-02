#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== Testing Bureaucrat creation ===" << std::endl;

	try
	{
		Bureaucrat failed("LowGrade", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat failedToo("HighGrade", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n=== Testing Form creation ===" << std::endl;
	try
	{
		Form badForm("TooHigh", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Form stillBadForm("TooLow", 151, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	Bureaucrat b1("Pro", 10);
	std::cout << b1 << std::endl;
	Bureaucrat b2("Noob", 50);
	std::cout << b2 << std::endl;
	Bureaucrat b3("Idiot", 100);
	std::cout << b3 << std::endl;
	Form f1("subscribeToMyOnlyfans", 15, 5);
	std::cout << f1 << std::endl;
	Form f2("orderSomeLean", 55, 35);
	std::cout << f2 << std::endl;
	Form f3("equalGrade", 100, 100);
	std::cout << f3 << std::endl;
	std::cout << "\nPro trying to sign forms\n" << std::endl;
	b1.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << "\n \Idiot tries to order some lean\n" << std::endl;
	b3.signForm(f2);
	std::cout << f2 << std::endl;
	std::cout << "\nNoob signs for Idiot\n" << std::endl;
	b2.signForm(f2);
	std::cout << f2 << std::endl;
	std::cout << "\nMaking Idiot sign a Form with the equal grade as him\n" << std::endl;
	b3.signForm(f3);
	std::cout << f3 << std::endl;

	return 0;
}
