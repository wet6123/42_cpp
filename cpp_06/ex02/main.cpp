#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Functions.hpp"

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
    return 0;
}