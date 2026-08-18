#include "ScalarConverter.hpp"
#include <sstream>
#include <cctype>
#include <climits>
#include <cfloat>
#include <iostream>

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{}

bool    ScalarConverter::ssFailure(std::stringstream& ss)
{
    if (ss.fail())
    {
        std::cout << "char: impossible\n"
        << "int: impossible\n"
        << "float: impossible\n"
        << "double: impossible" << std::endl;

        return false;
    }
    return true;
}

bool    ScalarConverter::isInt(std::string& str)
{
    size_t i = 0;

    if (str.empty())
        return false;

    if (str[i] == '+' || str[i] == '-')
        i++;

    if (i == str.length())
        return false;

    while (i < str.length())
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    
    return true;
}

bool    ScalarConverter::isDisplayableChar(double value)
{
    char c = static_cast<char>(value);

    if (!std::isprint(c))
        return false;
    return true;
}

bool    ScalarConverter::isValidChar(double value)
{
    if (value < 0 || value > 127)
        return false;
    return true;    
}

bool    ScalarConverter::isValidInt(double value)
{
    if (value < INT_MIN || value > INT_MAX)
        return false;
    return true;
}

bool    ScalarConverter::isValidFloat(double value)
{
    if (value < -FLT_MAX || value > FLT_MAX)
        return false;
    return true;
}

bool    ScalarConverter::isValidDouble(double value)
{
    if (value < -DBL_MAX || value > DBL_MAX)
        return false;
    return true;
}

void    ScalarConverter::convertInt(std::string& str)
{
    std::stringstream ss(str);
    double value;

    ss >> value;

    if (!ssFailure(ss))
        return;

    if (!isValidChar(value))
        std::cout << "char: impossible" << std::endl;
    else
    {
        if (!isDisplayableChar(value))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: \"" << static_cast<char>(value) << "\"" << std::endl;
    }

    if (!isValidInt(value))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    if (!isValidFloat(value))
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;

    if (!isValidDouble(value))
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
    
}

void    ScalarConverter::convert(std::string literal)
{
    if (isInt(literal))
        convertInt(literal);
}
