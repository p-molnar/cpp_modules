#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed x;
	Fixed y;

public:
	Point(void);
	Point(Fixed x, Fixed y);

	const Fixed &getX() const;
	const Fixed &getY() const;
	bool operator==(const Point &obj) const;
	bool operator!=(const Point &obj) const;

	Point(const Point &obj);

	Point &operator=(const Point &obj);

	~Point(void);
};

#endif
