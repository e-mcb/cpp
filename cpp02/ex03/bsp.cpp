#include "Point.hpp"

static Fixed cross(Point const p1, Point const p2, Point const p3)
{
	Fixed x1 = p2.getX() - p1.getX();
	Fixed y1 = p2.getY() - p1.getY();
	Fixed x2 = p3.getX() - p1.getX();
	Fixed y2 = p3.getY() - p1.getY();

	return (x1 * y2 - y1 * x2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed cross1 = cross(a, b, point);
	Fixed cross2 = cross(b, c, point);
	Fixed cross3 = cross(c, a, point);

	bool allPositive = (cross1 > Fixed(0)) && (cross2 > Fixed(0)) && (cross3 > Fixed(0));
	bool allNegative = (cross1 < Fixed(0)) && (cross2 < Fixed(0)) && (cross3 < Fixed(0));

	return (allPositive || allNegative);
}
