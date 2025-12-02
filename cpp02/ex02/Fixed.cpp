#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;

	long	fixedValue = intValue << _fractionalBits;

	if (fixedValue > std::numeric_limits<int>::max() ||
		fixedValue < std::numeric_limits<int>::min())
		throw (std::overflow_error("Fixed-point value overflow in int constructor"));

	_value = static_cast<int>(fixedValue);
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;

	double fixedValue = roundf(floatValue * (1 << _fractionalBits));

	if (fixedValue > std::numeric_limits<int>::max() ||
		fixedValue < std::numeric_limits<int>::min())
		throw (std::overflow_error("Fixed-point value overflow in float constructor"));

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
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_value - other._value);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	int64_t rawProduct = static_cast<int64_t>(this->getRawBits()) * other.getRawBits();

	int64_t scaledProduct = rawProduct >> _fractionalBits;

	if (scaledProduct > std::numeric_limits<int>::max() || 
		scaledProduct < std::numeric_limits<int>::min())
	{
		throw (std::overflow_error("Fixed-point value overflow in product operator '*'"));
	}

	Fixed result;
	result.setRawBits(static_cast<int>(scaledProduct));
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.getRawBits() == 0)
		throw (std::runtime_error("Division by zero in quotient operator '/'"));

	int64_t numerator = static_cast<int64_t>(this->getRawBits()) << _fractionalBits;
	int64_t resultRaw = numerator / other.getRawBits();

	if (resultRaw > std::numeric_limits<int>::max() ||
		resultRaw < std::numeric_limits<int>::min())
	{
		throw (std::overflow_error("Fixed-point value overflow in quotient operator '/'"));
	}

	Fixed result;
	result.setRawBits(static_cast<int>(resultRaw));
	return (result);
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_value != other._value;
}

Fixed& Fixed::operator++()
{
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_value += 1;
	return temp;
}

Fixed& Fixed::operator--()
{
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_value -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}
