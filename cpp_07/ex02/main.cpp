#include "Array.hpp"
#include "Array.tpp"
#include <iostream>


int main()
{
    Array<int> int_arr(5);
    Array<int> int_arr2;
    Array<std::string> str_arr(3);
    Array<std::string> str_arr2;

    int_arr[0] = 42;
    int_arr[1] = 1;
    int_arr[2] = 2;
    int_arr[3] = 3;
    int_arr[4] = 4;

    str_arr[0] = "Hello";
    str_arr[1] = "World";
    str_arr[2] = "!";

    std::cout << "---------- int ----------" << std::endl;
    std::cout << "int_arr_size: " << int_arr.size() << std::endl;
    for(size_t i = 0; i < int_arr.size(); i++)
        std::cout << "int_arr[" << i << "]: " << int_arr[i] << std::endl;

    std::cout << "int_arr_size: " << int_arr2.size() << std::endl;
    for(size_t i = 0; i < int_arr2.size(); i++)
        std::cout << "int_arr[" << i << "]: " << int_arr2[i] << std::endl;

    std::cout << "\n---------- str ----------" << std::endl;
    std::cout << "int_arr_size: " << str_arr.size() << std::endl;
    for(size_t i = 0; i < str_arr.size(); i++)
        std::cout << "int_arr[" << i << "]: " << str_arr[i] << std::endl;

    std::cout << "int_arr_size: " << str_arr2.size() << std::endl;
    for(size_t i = 0; i < str_arr2.size(); i++)
        std::cout << "int_arr[" << i << "]: " << str_arr2[i] << std::endl;
}