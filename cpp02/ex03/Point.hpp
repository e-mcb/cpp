#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point 
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();

	Point(const float xVal, const float yVal);

	Point(const Point& other);

	Point& operator=(const Point& other);

	~Point();

	Fixed getX() const;
	Fixed getY() const;

};

std::ostream& operator<<(std::ostream& os, const Point& p);

#endif
