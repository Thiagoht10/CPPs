#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>

class Span
{
private:
    unsigned int       _sizeMax;
    std::vector<int>   _numbers;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void    addNumber(int number);
    unsigned int    shortestSpan() const;
    unsigned int    longestSpan() const;

    template <typename Iterator>
    void    addNumber(Iterator begin, Iterator end)
    {
        while (begin != end)
        {
            if (_numbers.size() + 1 > _sizeMax)
                throw MaxSizeReachedException();
                
            _numbers.push_back(*begin);
            ++begin;
        }
    }

    class MaxSizeReachedException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class DistanceNotFound : public std::exception
    {
    public:
        const char* what() const throw();
    };
};


#endif