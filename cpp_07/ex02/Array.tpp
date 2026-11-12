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
    : _array(new T[other._size]), _size(other._size)
{
    try
    {
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    catch(...)
    {
        delete[] _array;
        throw;
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        T* tmp = new T[other._size];

        try
        {
            for (unsigned int i = 0; i < other._size; i++)
                tmp[i] = other._array[i];
        }
        catch (...)
        {
            delete[] tmp;
            throw;
        }

        delete[] _array;
        _array = tmp;
        _size = other._size;
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
    if (index >= _size)
        throw IndexOutBoundsException();
    
    return _array[index];
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

