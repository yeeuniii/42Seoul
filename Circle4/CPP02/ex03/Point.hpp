#pragma once
#ifndef __Point_HPP__
#define __Point_HPP__

#include "Fixed.hpp"

typedef class Point	Vector;

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point(void);
		Point(const Fixed x, const Fixed y);
		Point(const Point& point);
		~Point(void);
		Point& operator=(Point const& point);
		
		Fixed	getX() const;
		Fixed	getY() const;

};

Point	operator-(const Point &point1, const Point &point2);

#endif