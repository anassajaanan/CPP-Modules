#include "Point.hpp"
#include <iostream>


int main(void)
{
	Point const a(1, 1);
	Point const b(-2, -2);
	Point const c(3, -2);
	Point const point(0, -1);


	bool result = bsp(a, b, c, point);

	if (result)
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	return (0);
}