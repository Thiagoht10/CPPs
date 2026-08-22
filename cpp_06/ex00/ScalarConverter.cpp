#include "ScalarConverter.hpp"
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

bool    ScalarConverter::pseudoLiteral(std::string& str)
{
    if (str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible\n"
        << "int: impossible\n"
        << "float: nanf\n"
        << "double: nan" << std::endl;
        return true;
    }

    if (str == "+inff" || str == "+inf")
    {
        std::cout << "char: impossible\n"
        << "int: impossible\n"
        << "float: +inff\n"
        << "double: +inf" << std::endl;
        return true;
    }

    if (str == "-inff" || str == "-inf")
    {
        std::cout << "char: impossible\n"
        << "int: impossible\n"
        << "float: -inff\n"
        << "double: -inf" << std::endl;
        return true;
    }

    return false;
}

bool    ScalarConverter::isChar(std::string& str)
{
    if (str.length() != 1)
        return false;

    if (std::isdigit(static_cast<char>(str[0])))
        return false;

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

bool    ScalarConverter::isFloat(std::string& str)
{
    size_t  i = 0;
    bool hasDot = false;
    bool hasDigit = false;

    if (str.empty() || str[str.length() -1] != 'f')
        return false;

    if (str[i] == '+' || str[i] == '-')
        i++;

    while (i < str.length() - 1)
    {
        if (std::isdigit(static_cast<unsigned char>(str[i])))
            hasDigit = true;
        else if (str[i] == '.' && !hasDot)
            hasDot = true;
        else
            return false;
        i++;
    }

    return hasDigit && hasDot;
}

bool    ScalarConverter::isDouble(std::string& str)
{
    size_t  i = 0;
    bool hasDot = false;
    bool hasDigit = false;


    if (str.empty() || !std::isdigit(static_cast<int>(str[str.length() - 1])))
        return false;

    if (str[i] == '+' || str[i] == '-')
        i++;

    while (i < str.length() - 1)
    {
        if (std::isdigit(static_cast<unsigned char>(str[i])))
            hasDigit = true;
        else if (str[i] == '.' && !hasDot)
            hasDot = true;
        else
            return false;
        i++;
    }

    return hasDigit && hasDot;
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
    if (value <= -1.0 || value >= 128.0)
        return false;
    return true;    
}

bool    ScalarConverter::isValidInt(double value)
{
    if (value <= static_cast<double>(INT_MIN) - 1.0
        || value >= static_cast<double>(INT_MAX) + 1.0)
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

void    ScalarConverter::convertChar(std::string& str)
{
    char    value = str[0];

   std::cout << "char: \'" << value << "\'" << std::endl;
   std::cout << "int: " << static_cast<int>(value) << std::endl;
   std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
   std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void    ScalarConverter::convertInt(std::string& str)
{
    std::stringstream ss(str);
    int value;

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
            std::cout << "char: \'" << static_cast<char>(value) << "\'" << std::endl;
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

void    ScalarConverter::convertFloat(std::string& str)
{
    std::string tmp;
    tmp.assign(str.c_str(), str.length() - 1);

    std::stringstream ss(tmp);
    float value;

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
            std::cout << "char: \'" << static_cast<char>(value) << "\'" << std::endl;
    }

    if (!isValidInt(value))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    if (!isValidFloat(value))
        std::cout << "float: impossible" << std::endl;
    else
    {
        if (isValidInt(value) && value == static_cast<int>(value))
            std::cout << "float: " << value << ".0f" << std::endl;
        else
            std::cout << "float: " << value << "f" << std::endl;
    }

    if (!isValidDouble(value))
        std::cout << "double: impossible" << std::endl;
    else
    {
        if (isValidInt(value) && value == static_cast<int>(value))
            std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(value) << std::endl;

    }
}

void    ScalarConverter::convertDouble(std::string& str)
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
            std::cout << "char: \'" << static_cast<char>(value) << "\'" << std::endl;
    }

    if (!isValidInt(value))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    if (!isValidFloat(value))
        std::cout << "float: impossible" << std::endl;
    else
    {
        if (isValidInt(value) && value == static_cast<int>(value))
            std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }

    if (!isValidDouble(value))
        std::cout << "double: impossible" << std::endl;
    else
    {
        if (isValidInt(value) && value == static_cast<int>(value))
            std::cout << "double: " << value << ".0" << std::endl;
        else
            std::cout << "double: " << value << std::endl;
    }
}

void    ScalarConverter::convert(std::string literal)
{
    if (pseudoLiteral(literal))
        return;
    else if (isChar(literal))
        convertChar(literal);
    else if (isInt(literal))
        convertInt(literal);
    else if (isFloat(literal))
        convertFloat(literal);
    else if (isDouble(literal))
        convertDouble(literal);
    else
    {
        std::cout << "char: impossible\n"
        << "int: impossible\n"
        << "float: impossible\n"
        << "double: impossible" << std::endl;
    }
}
