#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void) other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string &str)
{
	const char	*cString = str.c_str();

	int			intCast = atoi(cString);
	float		floatCast = atof(cString);
	double		doubleCast = atof(cString);

	if (intCast >= 0 && intCast <= 126)
	{
		char charCast = (char)intCast;
		std::cout << "Char value is: " << charCast << std::endl;
	}

	std::cout << "Int value is: " << intCast << "\nFloat Value is: "
			  << floatCast << "f\nDouble value is: " << doubleCast << std::endl; 
}

void ScalarConverter::convert(std::string &str)
{
	
}