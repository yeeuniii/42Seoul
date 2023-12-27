#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point	a(Fixed(0), Fixed(0));
	Point	b(Fixed(4), Fixed(0));
	Point	c(Fixed(2), Fixed(4));
	
	std::cout << bsp(a, b, c, Point(Fixed(2), Fixed(2))) << std::endl;
	
	std::cout << bsp(a, b, c, Point(Fixed(20), Fixed(2))) << std::endl;
	std::cout << bsp(a, b, c, Point(Fixed(2), Fixed(4))) << std::endl;
	std::cout << bsp(a, b, c, Point(Fixed(3), Fixed(0))) << std::endl;
	
	std::cout << bsp(a, b, Point(Fixed(3), Fixed(0)), Point(Fixed(3), Fixed(0))) << std::endl;
	
	return 0;
}