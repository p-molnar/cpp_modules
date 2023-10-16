#include "Point.hpp"

Point::Point(void) {}

Point::Point(Fixed x, Fixed y)
	: x(x), y(y) {}

Point::Point(const Point &obj)
{
	x = obj.x;
	y = obj.y;
}

Point &Point::operator=(const Point &obj)
{
	x = obj.x;
	y = obj.y;
	return *this;
}

bool Point::operator==(const Point &obj) const
{
	return (x != obj.x) && (y != obj.y);
}

bool Point::operator!=(const Point &obj) const
{
	return (x != obj.x) || (y != obj.y);
}

Point::~Point(void)
{
}

const Fixed &Point::getX() const
{
	return x;
}

const Fixed &Point::getY() const
{
	return y;
}
