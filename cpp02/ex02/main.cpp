#include "Fixed.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

int main() 
{
	try 
	{
		std::cout << GREEN << "\n--- Constructors ---" << RESET << std::endl;
		Fixed a;
		Fixed b(10);
		Fixed c(42.42f);
		Fixed d(b);
		a = Fixed(1234.4321f);

		std::cout << "\na = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;

		std::cout << GREEN << "\n--- Conversion ---" << RESET << std::endl;
		std::cout << "b to int: " << b.toInt() << std::endl;
		std::cout << "c to float: " << c.toFloat() << std::endl;
		std::cout << "c to int: " << c.toInt() << std::endl;
		std::cout << "b to float: " << b.toFloat() << std::endl;

		std::cout << GREEN << "\n--- Arithmetic Operators ---" << RESET << std::endl;
		Fixed e = b + c;
		Fixed f = c - b;
		Fixed g = b * c;
		Fixed h = c / b;

		std::cout << "b + c = " << e << std::endl;
		std::cout << "c - b = " << f << std::endl;
		std::cout << "b * c = " << g << std::endl;
		std::cout << "c / b = " << h << std::endl;

		std::cout << GREEN << "\n--- Comparison Operators ---" << RESET << std::endl;
		std::cout << "b > c : " << (b > c) << std::endl;
		std::cout << "b < c : " << (b < c) << std::endl;
		std::cout << "b >= d : " << (b >= d) << std::endl;
		std::cout << "b <= d : " << (b <= d) << std::endl;
		std::cout << "b == d : " << (b == d) << std::endl;
		std::cout << "b != d : " << (b != d) << std::endl;

		std::cout << GREEN << "\n--- Increment / Decrement ---" << RESET << std::endl;
		Fixed i;
		std::cout << "i = " << i << std::endl;
		std::cout << "++i = " << ++i << std::endl;
		std::cout << "i++ = " << i++ << std::endl;
		std::cout << "i = " << i << std::endl;
		std::cout << "--i = " << --i << std::endl;
		std::cout << "i-- = " << i-- << std::endl;
		std::cout << "i = " << i << std::endl;

		std::cout << GREEN << "\n--- Min / Max ---" << RESET << std::endl;
		Fixed x(5.5f);
		Fixed y(10.1f);
		std::cout << "min(x, y) = " << Fixed::min(x, y) << std::endl;
		std::cout << "max(x, y) = " << Fixed::max(x, y) << std::endl;

		std::cout << GREEN << "\n--- Exception Test (Division by zero) ---" << RESET << std::endl;
		try 
		{
			Fixed zero;
			Fixed result = x / zero;
			std::cout << "x / zero = " << result << std::endl;
		}
		catch (const std::exception& e) 
		{
			std::cerr << RED << "Caught exception: " << e.what() << RESET << std::endl;
		}

		std::cout << GREEN << "\n--- Exception Test (Overflow) ---" << RESET << std::endl;
		try
		{
			Fixed bigInt(std::numeric_limits<int>::max() >> 1);
			Fixed bigFloat(1e9f);
			Fixed result = bigFloat * bigFloat;
			std::cout << "Result: " << result << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << "Caught overflow exception: " << e.what() << RESET << std::endl;
		}

		std::cout << GREEN << "\n--- End of Tests ---" << RESET << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << RED << "Unhandled exception: " << e.what() << RESET << std::endl;
	}
	return 0;
}
