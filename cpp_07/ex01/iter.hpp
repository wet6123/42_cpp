#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename U>
void iter(T* address, size_t length, U f)
{
    for (size_t i = 0; i < length; i++)
        f(address[i]);
}

#endif