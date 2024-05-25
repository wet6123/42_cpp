#include "Array.hpp"

template<typename T>
Array<T>::Array(void)
: _arr(new T[0]), _size(0)
{}

template<typename T>
Array<T>::Array(unsigned int n)
: _arr(new T[n]), _size(n)
{}

template<typename T>
Array<T>::Array(Array const &obj)
{
    this->_size = obj.size();
    this->_arr = new T[_size];
    for (size_t i = 0; i < _size; i++)
        this->_arr[i] = obj._arr[i];
}

template<typename T>
Array<T> &Array<T>::operator=(Array const &obj)
{
    if (this != &obj)
    {
        this->_size = obj.size();
        if (this->_arr != NULL)
        {
            delete[] this->_arr;
            this->_arr = NULL;
        }
        this->_arr = new T[_size];
        for (size_t i = 0; i < _size; i++)
            this->_arr[i] = obj._arr[i];
    }
    return (*this);
}

template<typename T>
Array<T>::~Array(void)
{
    delete[] _arr;
}

template<typename T>
size_t Array<T>::size(void) const
{
    return (_size);
}

template<typename T>
T &Array<T>::operator[](size_t index)
{
    if (index >= this->_size || index < 0)
        throw std::out_of_range("Index out of range");
    return (_arr[index]);
}

template<typename T>
T const &Array<T>::operator[](size_t index) const
{
    if (index >= this->_size || index < 0)
        throw std::out_of_range("Index out of range");
    return (_arr[index]);
}