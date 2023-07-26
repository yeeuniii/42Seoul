#include "Point.cpp"
#include <complex>

float	getLength(Point const p1, Point const p2)
{
	Fixed	length = (p1.getCoordinateX() - p2.getCoordinateX()) * (p1.getCoordinateX() - p2.getCoordinateX())
					+ (p1.getCoordinateY() - p2.getCoordinateY()) * (p1.getCoordinateY() - p2.getCoordinateY());
	return sqrt(length.toFloat());
}

bool	isTriangle(Point const a, Point const b, Point const c)
{
	float	length_a = getLength(b, c);
	float	length_b = getLength(a, c);
	float	length_c = getLength(a, b);
	bool	return_value;

	std::cout << length_a << std::endl;	
	std::cout << length_b << std::endl;	
	std::cout << length_c << std::endl;	
	if (length_a == 0 || length_b == 0 || length_c == 0)
		return false;
	return_value = length_a < length_b + length_c ? true : false;
	return_value = return_value && length_b < length_a + length_c ? true : false;
	return_value = return_value && length_c < length_a + length_b ? true : false;
	return return_value;
}


bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (isTriangle(a, b, c) == false)
	{
		std::cout << "These three points are not triangular." << std::endl;
		return false;
	}
	(void)point;
	return true;
}