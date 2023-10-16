#include "Point.hpp"
#include "Triangle.hpp"
#include "Fixed.hpp"

bool Triangle::isPointInside(const Point &p)
{
	Fixed x1 = v1.getX();
	Fixed x2 = v2.getX();
	Fixed x3 = v3.getX();

	Fixed y1 = v1.getY();
	Fixed y2 = v2.getY();
	Fixed y3 = v3.getY();

	Fixed px = p.getX();
	Fixed py = p.getY();

	Fixed m = 0.5f;
	Fixed A = m * Fixed::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
	Fixed A1 = m * Fixed::abs(px * (y2 - y3) + x2 * (y3 - py) + x3 * (py - y2));
	Fixed A2 = m * Fixed::abs(x1 * (py - y3) + px * (y3 - y1) + x3 * (y1 - py));
	Fixed A3 = m * Fixed::abs(x1 * (y2 - py) + x2 * (py - y1) + px * (y1 - y2));

	std::cout << A << '\n';
	std::cout << A1 << '\n';
	std::cout << A2 << '\n';
	std::cout << A3 << '\n';
	return A == (A1 + A2 + A3);
}
