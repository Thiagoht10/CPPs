#include "Span.hpp"
#include <algorithm>

Span::Span()
    : _sizeMax(0)
{}

Span::Span(unsigned int N)
    : _sizeMax(N)
{}

Span::Span(const Span& other)
    : _sizeMax(other._sizeMax), _numbers(other._numbers)
{}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _sizeMax = other._sizeMax;
        _numbers = other._numbers;
    }

    return *this;
}

Span::~Span()
{}

void    Span::addNumber(int number)
{
    if (_numbers.size() + 1 > _sizeMax)
        throw MaxSizeReachedException();

    _numbers.push_back(number);
}

unsigned int    Span::shortestSpan() const
{
    unsigned int shortesDiffFound;
    unsigned int diff = 0;

    if (_numbers.size() <= 1)
        throw DistanceNotFound();

    std::vector<int> tmp(_numbers);

    std::sort(tmp.begin(), tmp.end());

    std::vector<int>::iterator it = tmp.begin();

    it++;
    shortesDiffFound = static_cast<unsigned int>(*it) -
            static_cast<unsigned int>(*(it - 1));
    while(it != tmp.end())
    {
        diff = static_cast<unsigned int>(*it) -
            static_cast<unsigned int>(*(it - 1));
        if (diff < shortesDiffFound)
            shortesDiffFound = diff;
        it++;
    }
    return shortesDiffFound;
}

unsigned int    Span::longestSpan() const
{
    if (_numbers.size() <= 1)
        throw DistanceNotFound();

    std::vector<int> tmp(_numbers);

    std::sort(tmp.begin(), tmp.end());

    return static_cast<unsigned int>(tmp.back()) -
        static_cast<unsigned int>(tmp.front());
}

const char* Span::MaxSizeReachedException::what() const throw()
{
    return "full container";
}

const char* Span::DistanceNotFound::what() const throw()
{
    return "distance not found";
}