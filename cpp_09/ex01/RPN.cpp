#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <iostream>
#include <limits>
#include <stdexcept>

RPN::RPN()
{
    _max = std::numeric_limits<int>::max();
    _min = std::numeric_limits<int>::min();
}

RPN::RPN(const RPN& other)
    : _numbers(other._numbers), _max(other._max), _min(other._min)
{}

RPN&    RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
        _max = other._max;
        _min = other._min;
    }

    return *this;
}

RPN::~RPN()
{}

int RPN::sum(int a, int b) const
{
    if ((b > 0 && a > _max - b) || (b < 0 && a < _min - b))
        throw std::runtime_error("integer overflow");

    return a + b;
}

int RPN::subtraction(int a, int b) const
{
    if ((b > 0 && a < _min + b) || (b < 0 && a > _max + b))
        throw std::runtime_error("integer overflow");

    return a - b;
}

int RPN::multiplication(int a, int b) const
{
    if (a == 0 || b == 0)
        return 0;
    
    if (a > 0)
    {
        if ((b > 0 && a > _max / b) || (b < 0 && b < _min / a))
            throw std::runtime_error("integer overflow");
    }
    else
    {
        if ((b > 0 && a < _min / b) || (b < 0 && a < _max / b))
            throw std::runtime_error("integer overflow");
    }

    return a * b;
}

int RPN::division(int a, int b) const
{
    if (b == 0)
        throw std::runtime_error("division by zero");

    if (a == _min && b == -1)
        throw std::runtime_error("integer overflow");

    return a / b;
}

bool    RPN::isValidChar(const std::string& token) const
{
    if (token.size() != 1)
        return false;

    char c = token[0];

    if ((c >= '0' && c <= '9') || c == '+' || c == '-'
            || c == '*' || c == '/')
        return true;

    return false;
}

bool    RPN::addNumber(const std::string& token)
{
    std::stringstream ss(token);
    int number;

    ss >> number;

    if (ss.fail())
        return false;

    _numbers.push(number);

    return true;
}

void    RPN::calculate(const char token)
{
    int a;
    int b;
    int result;

    if (_numbers.size() < 2)
        throw std::runtime_error("insufficient operands");

    b = _numbers.top();
    _numbers.pop();

    a = _numbers.top();
    _numbers.pop();

    try
    {
        if (token == '+')
            result = sum(a, b);
        else if (token == '-')
            result = subtraction(a, b);
        else if (token == '*')
            result = multiplication(a, b);
        else
            result = division(a, b);
    }
    catch(const std::exception& e)
    {
        throw;
    }

    _numbers.push(result);
}

void    RPN::execute(const std::string numbers)
{
    std::istringstream st(numbers);
    std::string token;

    while (st >> token)
    {
        if (!isValidChar(token))
            throw std::runtime_error("invalid token");
        
        if (std::isdigit(token[0]))
        {
            if (!addNumber(token))
                throw std::runtime_error("Error");
        }
        else
        {
            try
            {
                calculate(token[0]);
            }
            catch(const std::exception& e)
            {
                throw;
            }
        }
    }

    if (_numbers.size() > 1)
        throw std::runtime_error("too many operands");
    else if (_numbers.size() == 0)
        throw std::runtime_error("empty expression");

    std::cout << _numbers.top() << std::endl;
}