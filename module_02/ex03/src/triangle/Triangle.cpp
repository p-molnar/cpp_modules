#include "Triangle.hpp"
#include "Point.hpp"
#include <cassert>

Triangle::Triangle(void) {}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
	bool condition = (p1 != p2) && (p1 != p3) && (p2 != p3);
	assert(condition && "2 or more identical points cannot define shape");

	v1 = p1;
	v2 = p2;
	v3 = p3;
}

Triangle::Triangle(const Triangle &obj)
{
	v1 = obj.v1;
	v2 = obj.v2;
	v3 = obj.v3;
}

Triangle &Triangle::operator=(const Triangle &obj)
{
	v1 = obj.v1;
	v2 = obj.v2;
	v3 = obj.v3;
	return *this;
}

Triangle::~Triangle(void) {}
