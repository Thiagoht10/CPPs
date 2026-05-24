#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {};

Fixed::~Fixed() {};

Fixed::Fixed(const Fixed& other)
{
    this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if(this != &other)
        this->_value = other._value;
    return (*this);
}

Fixed::Fixed(const int value)
{
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    _value = roundf(value * (1 << _fractionalBits));
}

int Fixed::getRawBits(void) const
{
    return (_value);
}

void    Fixed::setRawBits(const int raw)
{
    _value = raw;
}

int Fixed::toInt(void) const
{
    return (_value >> _fractionalBits);
}

float   Fixed::toFloat(void) const
{
    return (_value / static_cast<float>(1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return (os);
}

bool    Fixed::operator==(const Fixed& other) const
{
    return (this->_value == other._value);
}

bool    Fixed::operator!=(const Fixed& other) const
{
    return (this->_value != other._value);
}

bool    Fixed::operator>(const Fixed& other) const
{
    return (this->_value > other._value);
}

bool    Fixed::operator<(const Fixed& other) const
{
    return (this->_value < other._value);
}

bool    Fixed::operator<=(const Fixed& other) const
{
    return (this->_value <= other._value);
}

bool    Fixed::operator>=(const Fixed& other) const
{
    return (this->_value >= other._value);
}

Fixed   Fixed::operator+(const Fixed& other) const
{
    Fixed   result;

    result.setRawBits(this->_value + other._value);
    return (result);
}

Fixed   Fixed::operator-(const Fixed& other) const
{
    Fixed   result;

    result.setRawBits(this->_value - other._value);
    return (result);
}

Fixed   Fixed::operator/(const Fixed& other) const
{
    Fixed   result;

    result.setRawBits((this->_value << _fractionalBits) / other._value);
    return (result);
}

Fixed   Fixed::operator*(const Fixed& other) const
{
    Fixed   result;
    long    tmp;

    tmp = static_cast<long>(this->_value) * static_cast<long>(other._value);
    result.setRawBits(tmp >> _fractionalBits);
    return (result);
}

Fixed&  Fixed::operator++(void)
{
    this->_value++;
    return (*this);
}

Fixed  Fixed::operator++(int)
{
    Fixed tmp(*this);

    this->_value++;
    return(tmp);
}

Fixed&  Fixed::operator--(void)
{
    this->_value--;
    return(*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp(*this);
    
    this->_value--;
    return(tmp);
}

Fixed&  Fixed::min(Fixed& a, Fixed& b)
{
    if(a._value < b._value)
        return (a);
    return (b);
}

const Fixed&  Fixed::min(const Fixed& a, const Fixed& b)
{
    if(a._value < b._value)
        return (a);
    return (b);
}

Fixed&  Fixed::max(Fixed& a, Fixed& b)
{
    if(a._value > b._value)
        return (a);
    return (b);
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b)
{
    if(a._value > b._value)
        return (a);
    return (b);
}
