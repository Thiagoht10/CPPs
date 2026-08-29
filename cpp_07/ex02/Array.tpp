#include "Array.hpp"
#include <cstddef>

template <typename T>
Array<T>::Array()
    : _array(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _array = new T[n]();
    _size = n;
}

template <typename T>
Array<T>::Array(const Array& other)
{
    _size = other._size;

    _array = new T[_size];

    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        _size = other._size;
        delete[] _array;

        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index < _size)
        return _array[index];
    
    throw IndexOutBoundsException();
}

template <typename T>
unsigned int    Array<T>::size() const
{
    return _size;
}

template <typename T>
const char* Array<T>::IndexOutBoundsException::what() const throw()
{
    return "Index is out bounds";
}

