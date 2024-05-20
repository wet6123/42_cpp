#include "Functions.hpp"

Base * generate(void)
{
    std::srand(std::time(NULL));
    int i = std::rand() % 3;
    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        static_cast<void>(a);
    }
    catch (std::exception &e)
    {}
    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        static_cast<void>(b);
    }
    catch (std::exception &e)
    {}
    try
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        static_cast<void>(c);
    }
    catch (std::exception &e)
    {}
}