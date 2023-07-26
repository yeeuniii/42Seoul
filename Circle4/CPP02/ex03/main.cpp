#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	bsp(Point(Fixed(), Fixed()), Point(Fixed(4), Fixed(0)), Point(Fixed(2), Fixed(4)), Point(Fixed(2), Fixed(2)));
	
	bsp(Point(Fixed(1), Fixed(2)), Point(Fixed(-4), Fixed(-8)), Point(Fixed(10), Fixed(20)), Point(Fixed(-1), Fixed(10)));
	return 0;
}