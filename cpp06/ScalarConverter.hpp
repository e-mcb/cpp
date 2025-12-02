#pragma once

#include <iostream>
#include <sstream>
#include <cstdlib>

class ScalarConverter
{
public:
	ScalarConverter();
	virtual ~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);

	static void convert(std::string &str);
};
