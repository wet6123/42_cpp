#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template<typename T>
class Array
{
    public:
        T *_arr;
        size_t _size;

        Array(void);
        Array(unsigned int n);
        Array(Array const &obj);
        Array &operator=(Array const &obj);
        ~Array(void);
        size_t size(void) const;
        T &operator[](size_t index);
        const T &operator[](size_t index) const;
};

#endif