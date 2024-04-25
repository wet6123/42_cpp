#include "Point.hpp"
#include "Fixed.hpp"

int main(void)
{
    Point	a(1, 1);
	Point	b(2, 4);
	Point	c(6, 2);

	Point	p1(4, 2);
	Point	p2(3.48, 3.26);
	Point	p3(3.48, 3.25);

    if (bsp(a, b, c, p1))
		std::cout << "삼각형 안에 있음" << std::endl;
	else
		std::cout << "삼각형 안에 있지 않음" << std::endl;
	return 0;
}