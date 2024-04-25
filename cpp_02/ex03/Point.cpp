#include "Point.hpp"

Point::Point(void)
: x(0), y(0)
{}

Point::Point(const float x, const float y)
: x(x), y(y)
{}

Point::Point(const Point& obj)
: x(obj.getX()), y(obj.getY())
{}

Point& Point::operator=(const Point& obj)
{
  if (this != &obj)
  {
    this->~Point();
    new(this) Point(obj.getX().toFloat(), obj.getY().toFloat());
  }
	return (*this);
}

Point::~Point(void)
{}

Fixed Point::getX(void) const { return ( this->x ); }

Fixed Point::getY(void) const { return ( this->y ); }