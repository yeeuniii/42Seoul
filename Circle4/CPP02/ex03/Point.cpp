#include "Point.hpp"

Point::Point(void): x(0), y(0) {}

Point::Point(const Fixed x, const Fixed y): x(x), y(y) {}

Point::Point(const Point& point): x(point.getCoordinateX()), y(point.getCoordinateY()) {}

Point::~Point(void) {}

Point& Point::operator=(Point const& point)
{
	if (this != &point)
	{
	}
	return *this;
}

Fixed	Point::getCoordinateX() const
{
	return this->x;
}

Fixed	Point::getCoordinateY() const
{
	return this->y;
}