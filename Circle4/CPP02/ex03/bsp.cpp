#include "Point.cpp"
#include <complex>

float	getLength(Point const p1, Point const p2)
{
	Point	tmp = p1 - p2;
	Fixed	length = tmp.getX() * tmp.getX() + tmp.getY() * tmp.getY();
	
	return sqrt(length.toFloat());
}

bool	isTriangle(Point const a, Point const b, Point const c)
{
	float	length_a = getLength(b, c);
	float	length_b = getLength(a, c);
	float	length_c = getLength(a, b);
	bool	return_value;

	// std::cout << length_a << std::endl;	
	// std::cout << length_b << std::endl;	
	// std::cout << length_c << std::endl;	
	if (length_a == 0 || length_b == 0 || length_c == 0)
		return false;
	return_value = length_a < length_b + length_c ? true : false;
	return_value = return_value && length_b < length_a + length_c ? true : false;
	return_value = return_value && length_c < length_a + length_b ? true : false;
	return return_value;
}

bool	isIn(Vector const d1, Vector const d2, Vector const p)
{
	Fixed	denominator = d1.getX() * d2.getY() - d2.getX() * d1.getY();
	std::cout << denominator << std::endl;
	Fixed	t1 = (p.getX() * d2.getY() - p.getY() * d2.getX()) / denominator;
	Fixed	t2 = (p.getX() * d1.getY() - p.getY() * d1.getX()) / denominator * -1;

	std::cout << "t1 = " << t1 << std::endl;	
	std::cout << "t2 = " << t2 << std::endl;	
	return (t1 >= 0 && t1 <= 1) && (t2 >= 0 && t2 <= 1) && (t1 + t2 <= 1);
}   

bool	calculate(Point const a, Point const b, Point const c, Point const point)
{
	Vector	d1 = b - a;
	Vector	d2 = c - a;
	Vector	p = point - a;

	return isIn(d1, d2, p);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (isTriangle(a, b, c) == false)
	{
		std::cout << "These three points are not triangular." << std::endl;
		return false;
	}
	return calculate(a, b, c, point);
}