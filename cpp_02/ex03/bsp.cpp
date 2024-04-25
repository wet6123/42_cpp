#include "Point.hpp"
#include <cmath>

float area (Point const p1, Point const p2, Point const p3)
{
    Fixed tmp = p1.getX() * (p3.getY() - p2.getY()) + p2.getX() * (p1.getY() - p3.getY()) + p3.getX() * (p2.getY() - p1.getY());
    return (std::fabs(tmp.toFloat()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    // check point
    float area1 = area(a, b, c);
    float area2 = 0;
    area2 += area(point, a, b);
    area2 += area(point, b, c);
    area2 += area(point, c, a);

    std::cout << area1 << std::endl;
    std::cout << area2 << std::endl;
    std::cout << "change bsp" << std::endl;

    // in the triangle - return true
    if (area1 == area2)
        return (true);
    // vertex or on edge - return false
    return (false);

    // 이 방식의 문제점 edge에 있는 경우 true로 나옴
}

// https://hi-develop.tistory.com/20
// 
// function isPointInTriangle(
//   pointX: number,
//   pointY: number,
//   x1: number,
//   y1: number,
//   x2: number,
//   y2: number,
//   x3: number,
//   y3: number
// ) {
//   const a = (x1 - pointX) * (y2 - y1) - (x2 - x1) * (y1 - pointY);
//   const b = (x2 - pointX) * (y3 - y2) - (x3 - x2) * (y2 - pointY);
//   const c = (x3 - pointX) * (y1 - y3) - (x1 - x3) * (y3 - pointY);
//   return (a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0);
// }