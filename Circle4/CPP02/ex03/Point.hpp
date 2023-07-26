#pragma once
#ifndef __Point_HPP__
#define __Point_HPP__

#include "Fixed.hpp"

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
		
		Fixed	getCoordinateX() const;
		Fixed	getCoordinateY() const;
};

#endif