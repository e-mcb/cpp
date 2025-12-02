#include "bsp.hpp"

int main()
{
	Point a(0, 3);
	Point b(2, 0);
	Point c(0, 0);
	Point test1(0, 3);
	// Point test2(3, 0);
	std::cout << bsp(a, b, c, test1) << std::endl;
	// std::cout << bsp(a, b, c, test2) << std::endl;
}