#include "PmergeMe.hpp"
#include <cctype>
#include <stdexcept>
#include <sstream>
#include <iostream>

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _beforeSort(other._beforeSort), _vector(other._vector),
    _mainChain(other._mainChain), _pending(other._pending),
    _deque(other._deque)
{}

PmergeMe&   PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
        _beforeSort = other._beforeSort;
        _mainChain = other._mainChain;
        _pending = other._pending;
    }

    return *this;
}

PmergeMe::~PmergeMe()
{}

bool    PmergeMe::parsing(char* argv[]) const
{
    for (size_t i = 1; argv[i]; i++)
    {
        std::stringstream ss(argv[i]);
        std::string token;
        size_t pos;

        ss >> std::ws;
        if (ss.eof())
            return false;
        
        while (ss >> token)
        {
            if (token.find_first_of("-.") != std::string::npos)
                return false;

            for (size_t i = 0; i < token.size(); i++)
            {
                pos = token.find('+', i);
                if (pos != std::string::npos && pos != 0)
                    return false;
            }
            
            for (size_t j = 0; j < token.size(); j++)
            {
                if (!std::isdigit(token[j]) && token[j] != '+')
                    return false;
            }
        }
    }

    return true;
}

bool    PmergeMe::addNumbers(char* argv[])
{
    for (size_t i = 1; argv[i]; i++)
    {
        std::stringstream ss(argv[i]);
        int number;

        while (ss >> number)
        {                
            _vector.push_back(number);
            _deque.push_back(number);

            if (ss.eof())
                break;
        }

        if (ss.fail())
            return false;
    }

    return true;
}

void    PmergeMe::saveOriginalValues()
{
    std::stringstream ss;
    size_t size = _vector.size();

    for (size_t i = 0; i < size; i++)
    {
        ss << _vector[i];
        if (i < size - 1)
            ss << " ";
    }

    _beforeSort = ss.str();
}

void    PmergeMe::sortVectorPairs()
{
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        if (_vector[i] > _vector[i + 1])
            std::swap(_vector[i], _vector[i + 1]);
    }
}

//mudar esta função
void    PmergeMe::sortVectorPairsByMax()
{
    bool sorted = false;

    while (!sorted)
    {
        bool wasChanged = false;

        for (size_t i = 1; i + 2 < _vector.size(); i += 2)
        {
            if (_vector[i] > _vector[i + 2])
            {
                std::swap(_vector[i - 1], _vector[i + 1]);
                std::swap(_vector[i], _vector[i + 2]);

                wasChanged = true;
            }
        }
        if (!wasChanged)
            sorted = true;
    }      
}

void    PmergeMe::buildMainAndPending()
{
    size_t size = _vector.size();

    _mainChain.push_back(_vector[0]);

    for (size_t i = 1; i < size; i += 2)
        _mainChain.push_back(_vector[i]);

    for (size_t i = 2; i + 1 < size; i += 2)
        _pending.push_back(_vector[i]);

    if (size > 1 && size % 2 != 0)
        _pending.push_back(_vector[size - 1]);
}

void    PmergeMe::execute(char* argv[])
{
    if (!parsing(argv))
        throw std::runtime_error("invalid input");

    if (!addNumbers(argv))
        throw std::runtime_error("failure to add numbers");

    saveOriginalValues();
    sortVectorPairs();
    sortVectorPairsByMax();
    buildMainAndPending();
}

void    PmergeMe::printAll()
{
    size_t size = _vector.size();
    
    std::cout << "before: " << _beforeSort << std::endl;

    std::cout << "vector: ";
    for (size_t i = 0; i < size; i++)
        std::cout << _vector[i] << " ";

    std::cout << std::endl;

    std::cout << "mainChain: ";
    for (size_t i = 0; i < _mainChain.size(); i++)
        std::cout << _mainChain[i] << " ";

    std::cout << std::endl;

    std::cout << "pending: ";
    for (size_t i = 0; i < _pending.size(); i++)
        std::cout << _pending[i] << " ";

    std::cout << std::endl;

    std::cout << "deque: ";
    for (size_t i = 0; i < size; i++)
        std::cout << _deque[i] << " ";
    
    std::cout << std::endl;
}
