#include "iter.hpp"
#include <iostream>

void print(int &value)
{
    std::cout << value << std::endl;
}

void print(std::string &value)
{
    std::cout << value << std::endl;
}

int main()
{
    int int_arr[] = {1, 2, 3, 4, 5};
    std::string str_arr[] = {"Hello", "42", "World", "!!"};

    ::iter(int_arr, (sizeof(int_arr)/sizeof(int)), print);
    ::iter(str_arr, (sizeof(str_arr)/sizeof(std::string)), print);
}