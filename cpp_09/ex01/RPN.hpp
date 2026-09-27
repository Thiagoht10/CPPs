#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
private:
    std::stack<int> _numbers;
    int _max;
    int _min;

    int     sum(int a, int b) const;
    int     subtraction(int a, int b) const;
    int     multiplication(int a, int b) const;
    int     division(int a, int b) const;

    bool    isValidChar(const std::string& token) const;
    bool    addNumber(const std::string& token);
    void    calculate(const char token);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    void    execute(const std::string numbers);
};


#endif