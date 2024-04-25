#include "Point.hpp"
#include <cmath>

// float area (Point const p1, Point const p2, Point const p3)
// {
//     Fixed tmp = p1.getX() * (p3.getY() - p2.getY()) + p2.getX() * (p1.getY() - p3.getY()) + p3.getX() * (p2.getY() - p1.getY());
//     return (std::fabs(tmp.toFloat()));
// }

// bool bsp( Point const a, Point const b, Point const c, Point const point )
// {
//     // check point
//     float area1 = area(a, b, c);
//     float area2 = 0;
//     area2 += area(point, a, b);
//     area2 += area(point, b, c);
//     area2 += area(point, c, a);

//     std::cout << area1 << std::endl;
//     std::cout << area2 << std::endl;
//     std::cout << "change bsp" << std::endl;

//     // in the triangle - return true
//     if (area1 == area2)
//         return (true);
//     // vertex or on edge - return false
//     return (false);

//     // 이 방식의 문제점 edge에 있는 경우 true로 나옴
// }

Fixed sign(const Point point, const Point a, const Point b)
{
  // 주의 point는 b점이 될수 없음!
  return (point.getX() - b.getX()) * (a.getY() - b.getY()) -
         (a.getX() - b.getX()) * (point.getY() - b.getY());
}

bool bsp( const Point a, const Point b, const Point c, const Point point )
{
  Fixed d1, d2, d3;
  bool is_neg, is_pos;

  d1 = sign(point, a, b);
  d2 = sign(point, b, c);
  d3 = sign(point, c, a);

  is_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
  is_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
  return !(is_neg && is_pos);
}
