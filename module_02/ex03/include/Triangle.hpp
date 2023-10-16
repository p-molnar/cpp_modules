#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Point.hpp"

class Triangle
{
private:
	Point v1;
	Point v2;
	Point v3;

	static Point getCenterPoint(const Triangle &t);
	Point *getSortedVerticesCW();

public:
	Triangle(void);
	Triangle(Point p1, Point p2, Point p3);
	Fixed getArea() const;
	bool isInsideShape(const Point &p);

	Triangle(const Triangle &obj);
	Triangle &operator=(const Triangle &obj);
	bool isPointInside(const Point &p);
	~Triangle(void);
};

#endif
