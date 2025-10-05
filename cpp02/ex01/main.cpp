#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);

    // Example of calling the float constructor with error handling:
    /*
    try {
        Fixed bigFloat(1e10f); // This might throw if overflow detected
    }
    catch (const std::overflow_error& e) {
        std::cerr << "Overflow error: " << e.what() << std::endl;
    }
    */

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
