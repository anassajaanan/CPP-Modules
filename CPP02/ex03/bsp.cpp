#include "Point.hpp"
#include <iostream>

static float	calculateTriangleArea(const Point p1, const Point p2, const Point p3)
{
	float	area = p1.getX() * (p2.getY() - p3.getY()) + p2.getX() * (p3.getY() - p1.getY()) + p3.getX() * (p1.getY() - p2.getY());
	if (area < 0)
		area *= -1;
	area *= 0.5;
	return (area);
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	A = calculateTriangleArea(a, b, c);
	float	A1 = calculateTriangleArea(a, b, point);
	float	A2 = calculateTriangleArea(a, c, point);
	float	A3 = calculateTriangleArea(b, c, point);
	if (A1 == 0 || A2 == 0 || A3 == 0)
		return (false);
	float	sum = A1 + A2 + A3;

	// std::cout << "A: " << A << std::endl;
	// std::cout << "A1: " << A1 << std::endl;
	// std::cout << "A2: " << A2 << std::endl;
	// std::cout << "A3: " << A3 << std::endl;
	// std::cout << "sum: " << sum << std::endl;
	
	if (sum == A)
		return (true);
	return (false);

}