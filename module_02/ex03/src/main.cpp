#include "Fixed.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include <cstdlib>
#include <iostream>

void f(void)
{
	system("leaks point_in_triangle");
}

int main(void)
{
	// atexit(f);

	// must come in counter clock wise order
	// a point placed on the side of the triangle is deemed to be inside
	// the triangle
	Point p1(0, 0);
	Point p2(5, 0);
	Point p3(0, 5);

	Point p(0, 5);

	Triangle triangle(p1, p2, p3);

	std::cout << triangle.isPointInside(p) << '\n';

	return EXIT_SUCCESS;
}
