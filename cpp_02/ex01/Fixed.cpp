#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    _value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called\n";
    this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if(this != &other)
        this->_value = other._value;
    return (*this);
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called\n";
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called\n";
    _value = roundf(value *(1 << _fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (_value);
}

void    Fixed::setRawBits(int const raw)
{
    _value = raw;
}

int Fixed::toInt(void) const
{
    return (_value >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
    return (_value / static_cast<float>(1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return (os);
}