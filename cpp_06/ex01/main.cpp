#include "Serialize.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data data;
    data.s = "Hello, world!";
    data.n = 42;

    uintptr_t raw = serialize(&data);
    Data *ptr = deserialize(raw);

    std::cout << "Data: " << ptr->s << " " << ptr->n << std::endl;

    delete ptr;
    return 0;
}