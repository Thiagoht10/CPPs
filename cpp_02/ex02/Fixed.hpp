#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(const int raw);
    int     toInt(void) const;
    float   toFloat(void) const;

    bool    operator==(const Fixed& other) const;
    bool    operator!=(const Fixed& other) const;
    bool    operator>(const Fixed& other) const;
    bool    operator<(const Fixed& other) const;
    bool    operator<=(const Fixed& other) const;
    bool    operator>=(const Fixed& other) const;

    Fixed     operator+(const Fixed& other) const;
    Fixed     operator-(const Fixed& other) const;
    Fixed     operator/(const Fixed& other) const;
    Fixed     operator*(const Fixed& other) const;

    Fixed&  operator++(void);
    Fixed   operator++(int);
    Fixed&  operator--(void);
    Fixed   operator--(int);

    static Fixed&  min(Fixed& a, Fixed& b);
    static const Fixed&  min(const Fixed& a, const Fixed& b);
    static Fixed&  max(Fixed& a, Fixed& b);
    static const Fixed&  max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif