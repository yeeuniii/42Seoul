#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	std::cout << bsp(Point(Fixed(), Fixed()), Point(Fixed(4), Fixed(0)), Point(Fixed(2), Fixed(4)), Point(Fixed(2), Fixed(2))) << std::endl;
	std::cout << bsp(Point(Fixed(), Fixed()), Point(Fixed(4), Fixed(0)), Point(Fixed(2), Fixed(4)), Point(Fixed(20), Fixed(2))) << std::endl;
	
	return 0;
}