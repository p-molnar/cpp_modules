#include "Point.hpp"
#include "Triangle.hpp"
#include "Fixed.hpp"
#include <math.h>

typedef struct PtAgl
{
	Point p;
	Fixed angle;
} PtAgl;

Point Triangle::getCenterPoint(const Triangle &t)
{
	Fixed center_x = (t.v1.getX() + t.v2.getX() + t.v3.getX()) / 3;
	Fixed center_y = (t.v1.getY() + t.v2.getY() + t.v3.getY()) / 3;

	return Point(center_x, center_y);
}

Point *Triangle::getSortedVerticesCW()
{
	Point center = getCenterPoint(*this);
	Fixed agl_1 = atan2((v1.getY() - center.getY()).toFloat(), (v1.getX() - center.getX()).toFloat());
	Fixed agl_2 = atan2((v2.getY() - center.getY()).toFloat(), (v2.getX() - center.getX()).toFloat());
	Fixed agl_3 = atan2((v3.getY() - center.getY()).toFloat(), (v3.getX() - center.getX()).toFloat());

	PtAgl pt_agl[3] = {{v1, agl_1},
					   {v2, agl_2},
					   {v3, agl_3}};

	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (pt_agl[i].angle < pt_agl[j].angle)
			{
				PtAgl tmp = pt_agl[i];
				pt_agl[i] = pt_agl[j];
				pt_agl[j] = tmp;
			}
		}
	}
	Point *v_sorted = new Point[3];
	for (int i = 0; i < 3; i++)
		v_sorted[i] = pt_agl[i].p;
	return v_sorted;
}

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
