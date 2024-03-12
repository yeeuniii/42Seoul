#include "Point.hpp"

Point::Point(void): x(0), y(0) {}

Point::Point(const Fixed x, const Fixed y): x(x), y(y) {}

Point::Point(const Point& point): x(point.getX()), y(point.getY()) {}

Point::~Point(void) {}

Point& Point::operator=(Point const& point)
{
	if (this != &point)
	{
	}
	return *this;
}

Fixed	Point::getX() const
{
	return this->x;
}

Fixed	Point::getY() const
{
	return this->y;
}

Point	operator-(const Point &point1, const Point &point2)
{
	return Point(point1.getX() - point2.getX(), point1.getY() - point2.getY());
}