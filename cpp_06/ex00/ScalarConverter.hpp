#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
    static bool     ssFailure(std::stringstream& ss);

    static bool     isInt(std::string& str);
    static bool     isChar(std::string& str);
    static bool     isFloat(std::string& str);
    static bool     isDouble(std::string& str);

    static bool     isDisplayableChar(double value);
    static bool     isValidChar(double value);
    static bool     isValidInt(double value);
    static bool     isValidFloat(double value);
    static bool     isValidDouble(double value);

    static void     convertInt(std::string& str);

    ScalarConverter(void);
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    static void convert(std::string literal);

};

#endif