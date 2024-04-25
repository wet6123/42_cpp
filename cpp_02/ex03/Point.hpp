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

float area ( Point const p1, Point const p2, Point const p3 );
bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
