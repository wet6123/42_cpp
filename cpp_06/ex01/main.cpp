#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data data;
    data.s = "Hello, world!";
    data.n = 42;

    uintptr_t raw = Serializer::serialize(&data);
    Data *ptr = Serializer::deserialize(raw);

    std::cout << "Data: " << ptr->s << " " << ptr->n << std::endl;

    return 0;
}