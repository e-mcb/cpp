#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    _value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;

    double fixedValue = roundf(floatValue * (1 << _fractionalBits));

    if (fixedValue > std::numeric_limits<int>::max() || fixedValue < std::numeric_limits<int>::min())
        throw std::overflow_error("Fixed-point value overflow in float constructor");

    _value = static_cast<int>(fixedValue);
}


Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    _value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

