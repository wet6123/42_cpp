#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
		Point(void);
		Point& operator=(const Point& obj);
	public:
		Point(const float x, const float y);
		Point(const Point& obj);
		~Point(void);
		Fixed getX(void) const;
		Fixed getY(void) const;
};

Fixed sign(const Point point, const Point a, const Point b);
bool bsp( const Point a, const Point b, const Point c, const Point point );

#endif
