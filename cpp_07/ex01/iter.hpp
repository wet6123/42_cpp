#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T* address, size_t length, void (*f)(T &value))
{
    for (size_t i = 0; i < length; i++)
        f(address[i]);
}

#endif