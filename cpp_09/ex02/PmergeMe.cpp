#include "PmergeMe.hpp"
#include <cctype>
#include <stdexcept>
#include <sstream>
#include <iostream>

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _beforeSort(other._beforeSort), _pairs(other._pairs), _vector(other._vector),
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
        _pairs = other._pairs;
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

void    PmergeMe::buildVectorPairs()
{
    _pairs.clear();

    for (size_t i = 1; i < _vector.size(); i += 2)
    {
        Pairs pair;

        pair.small = _vector[i - 1];
        pair.large = _vector[i];

        pair.id = _pairs.size();
        _pairs.push_back(pair);
    }
}

void    PmergeMe::buildWinners(std::vector<Pairs>& pairs, std::vector<Pairs>& winners,
        std::vector<Losers>& losers)
{
    winners.clear();

    Losers loser;

    for (size_t i = 0; i + 1 < pairs.size(); i += 2)
    {
        if (pairs[i].large > pairs[i + 1].large)
        {
            winners.push_back(pairs[i]);
            loser.pair = pairs[i + 1];
            loser.winnerId = pairs[i].id;
        }
        else
        {
            winners.push_back(pairs[i + 1]);
            loser.pair = pairs[i];
            loser.winnerId = pairs[i + 1].id;
        }

        losers.push_back(loser);
    }
}

//mudar esta função
void    PmergeMe::sortVectorPairsByMax(std::vector<Pairs>& pairs)
{
    if (pairs.size() <= 1)
        return;
    
    bool hasLeftover = (pairs.size() % 2 != 0);
    Pairs leftover;

    if (hasLeftover)
        leftover = pairs.back();
        
    std::vector<Pairs> winners;
    std::vector<Losers> losers;

    buildWinners(pairs, winners, losers);

    sortVectorPairsByMax(winners);

    std::vector<Pairs> pending;

    for (size_t i = 0; i < winners.size(); i++)
    {
        for (size_t j = 0; j < losers.size(); j++)
        {
            if (losers[j].winnerId == winners[i].id)
            {
                pending.push_back(losers[j].pair);
                break;
            }
        }
    }

    if (hasLeftover)
        pending.push_back(leftover);

    pairs = buildSequence(winners, pending);
}

std::vector<Pairs>  PmergeMe::buildSequence(std::vector<Pairs>& winners,
        std::vector<Pairs>& pending)
{
     std::vector<Pairs> sequence(winners);
    sequence.insert(sequence.begin(), pending[0]);

    // Inserir os demais pendentes em blocos de Jacobsthal.
    size_t processed = 1;
    size_t previousJacob = 1;
    size_t jacob = 3;

    while (processed < pending.size())
    {
        size_t end = jacob;

        if (end > pending.size())
            end = pending.size();

        for (size_t position = end; position > processed; position--)
        {
            size_t index = position - 1;
            size_t limit = sequence.size();

            // A sobra não tem vencedor: usa a cadeia inteira.
            if (index < winners.size())
            {
                // Encontrar a posição atual do vencedor associado.
                for (size_t j = 0; j < sequence.size(); j++)
                {
                    if (sequence[j].id == winners[index].id)
                    {
                        limit = j;
                        break;
                    }
                }
            }

            // Buscar a posição de inserção antes do vencedor.
            size_t left = 0;
            size_t right = limit;

            while (left < right)
            {
                size_t middle = left + (right - left) / 2;

                if (sequence[middle].large < pending[index].large)
                    left = middle + 1;
                else
                    right = middle;
            }

            sequence.insert(sequence.begin() + left, pending[index]);
        }

        processed = end;

        size_t nextJacob = jacob + 2 * previousJacob;
        previousJacob = jacob;
        jacob = nextJacob;
    }

    return sequence;
}

//mudar esta função. Recebe dois parâmetros: mainchain e pending
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
    buildVectorPairs();
    sortVectorPairsByMax(_pairs);
    //criar a função sortVector que aplicará o jacobsthal e chamará a função abaixo
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
