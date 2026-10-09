#include "PmergeMe.hpp"
#include <cctype>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <ctime>

PmergeMe::PmergeMe()
    : _vectorTime(0.0), _dequeTime(0.0)
{}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _vectorTime(other._vectorTime), _dequeTime(other._dequeTime), 
    _beforeSort(other._beforeSort), _pairsVector(other._pairsVector), 
    _vector(other._vector), _pairsDeque(other._pairsDeque), _deque(other._deque)
{}

PmergeMe&   PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
        _beforeSort = other._beforeSort;
        _pairsVector = other._pairsVector;
        _vector = other._vector;
        _pairsDeque = other._pairsDeque;
        _deque = other._deque;
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

        ss >> std::ws;
        if (ss.eof())
            return false;
        
        while (ss >> token)
        {

            if (token.find_first_of("-.") != std::string::npos)
                return false;

            if (token.find('+', 1) != std::string::npos)
                return false;
            
            for (size_t j = 0; j < token.size(); j++)
            {
                unsigned char secureToken = static_cast<unsigned char>(token[j]);

                if (!std::isdigit(secureToken) && token[j] != '+')
                    return false;
            }

            if (ss.eof())
                break;
        }
    }

    return true;
}

bool    PmergeMe::addNumbersVector(char* argv[])
{
    for (size_t i = 1; argv[i]; i++)
    {
        std::stringstream ss(argv[i]);
        int number;

        while (true)
        {
            ss >> std::ws;
        
            if (ss.eof())
                break;
        
            if (!(ss >> number) || number <= 0)
                return false;
        
            _vector.push_back(number);
        }
    }

    return true;
}

bool    PmergeMe::addNumbersDeque(char* argv[])
{
    for (size_t i = 1; argv[i]; i++)
    {
        std::stringstream ss(argv[i]);
        int number;

        while (true)
        {
            ss >> std::ws;
        
            if (ss.eof())
                break;
        
            if (!(ss >> number) || number <= 0)
                return false;
        
            _deque.push_back(number);
        }
    }

    return true;
}

void    PmergeMe::saveOriginalValues(char* argv[])
{
    std::stringstream ss;
    bool first = true;

    for (size_t i = 1; argv[i]; i++)
    {
        std::stringstream ssn(argv[i]);
        int number;

        while (ssn >> number)
        {
            if (!first)
                ss << " ";
        
            ss << number;
            first = false;
        }
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
    _pairsVector.clear();

    for (size_t i = 1; i < _vector.size(); i += 2)
    {
        Pairs pair;

        pair.small = _vector[i - 1];
        pair.large = _vector[i];

        pair.id = _pairsVector.size();
        _pairsVector.push_back(pair);
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

void    PmergeMe::sortVector()
{
    if (_vector.size() <= 1)
        return;
    
    std::vector<ChainElement> mainChain;
    std::vector<int> pending;
    std::vector<int> result;

    buildMainAndPending(mainChain, pending);
    insertPending(mainChain, pending);

    for (size_t i = 0; i < mainChain.size(); i++)
        result.push_back(mainChain[i].value);

    _vector = result;
}

//mudar esta função. Recebe dois parâmetros: mainchain e pending
void    PmergeMe::buildMainAndPending(std::vector<ChainElement>& mainChain,
        std::vector<int>& pending)
{

    for (size_t i = 0; i < _pairsVector.size(); i++)
    {
        ChainElement element;

        element.value = _pairsVector[i].large;
        element.pairId = _pairsVector[i].id;

        mainChain.push_back(element);

        pending.push_back(_pairsVector[i].small);
    }

    if (_vector.size() % 2 != 0)
        pending.push_back(_vector.back());    
}

void    PmergeMe::insertPending(std::vector<ChainElement>& mainChain,
        std::vector<int>& pending)
{
    size_t processed = 1;
    size_t previousJacob = 1;
    size_t jacob = 3;

    ChainElement firstElement;

    firstElement.value = _pairsVector[0].small;
    firstElement.pairId = _pairsVector[0].id;

    mainChain.insert(mainChain.begin(), firstElement);

    while (processed < pending.size())
    {
        size_t end = jacob;

        if (end > pending.size())
            end = pending.size();

        for (size_t position = end; position > processed; position--)
        {
            size_t index = position - 1;
            size_t limit = mainChain.size();

            if (index < _pairsVector.size())
            {
                for (size_t i = 0; i < mainChain.size(); i++)
                {
                    if (mainChain[i].pairId == _pairsVector[index].id)
                    {
                        limit = i;
                        break;
                    }
                }
            }

            size_t left = 0;
            size_t right = limit;

            while (left < right)
            {
                size_t middle = left + (right - left) / 2;

                if (mainChain[middle].value < pending[index])
                    left = middle + 1;
                else
                    right = middle;
            }
            ChainElement element;
            element.value = pending[index];
            element.pairId = index < _pairsVector.size()
                ? _pairsVector[index].id : _pairsVector.size();
            
            mainChain.insert(mainChain.begin() + left, element);
        }

        processed = end;

        size_t nextJacob = jacob + 2 * previousJacob;
        previousJacob = jacob;
        jacob = nextJacob;
    }    
}

void    PmergeMe::executeVector()
{
    sortVectorPairs();
    buildVectorPairs();
    sortVectorPairsByMax(_pairsVector);
    sortVector();
}

void    PmergeMe::sortDequePairs()
{
    for (size_t i = 0; i + 1 < _deque.size(); i += 2)
    {
        if (_deque[i] > _deque[i + 1])
            std::swap(_deque[i], _deque[i + 1]);
    }
}

void    PmergeMe::buildDequePairs()
{
    _pairsDeque.clear();

    for (size_t i = 1; i < _deque.size(); i += 2)
    {
        Pairs pairs;

        pairs.large = _deque[i];
        pairs.small = _deque[i - 1];
        pairs.id = _pairsDeque.size();

        _pairsDeque.push_back(pairs);
    }
}

void    PmergeMe::buildWinners(std::deque<Pairs>& pairs, std::deque<Pairs>& winners,
        std::deque<Losers>& losers)
{
    winners.clear();

    for (size_t i = 1; i < pairs.size(); i += 2)
    {
        Losers loser;

        if (pairs[i].large > pairs[i - 1].large)
        {
            winners.push_back(pairs[i]);
            loser.pair = pairs[i - 1];
            loser.winnerId = pairs[i].id;
        }
        else
        {
            winners.push_back(pairs[i - 1]);
            loser.pair = pairs[i];
            loser.winnerId = pairs[i - 1].id;
        }

        losers.push_back(loser);
    }
}

void    PmergeMe::sortDequePairsByMax(std::deque<Pairs>& pairs)
{
    if (pairs.size() <= 1)
        return;

    bool hasLeftover = (pairs.size() % 2 != 0);
    Pairs leftover;

    if (hasLeftover)
        leftover = pairs.back();

    std::deque<Pairs> winners;
    std::deque<Losers> losers;

    buildWinners(pairs, winners, losers);

    sortDequePairsByMax(winners);

    std::deque<Pairs> pending;

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

std::deque<Pairs> PmergeMe::buildSequence(std::deque<Pairs>& winners,
        std::deque<Pairs>& pending)
{
    std::deque<Pairs> sequence(winners);
    sequence.insert(sequence.begin(), pending[0]);

    size_t processed = 1;
    size_t previusJacob = 1;
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

            if (index < winners.size())
            {
                for (size_t j = 0; j < sequence.size(); j++)
                {
                    if (sequence[j].id == winners[index].id)
                    {
                        limit = j;
                        break;
                    }
                }
            }

            size_t right = limit;
            size_t left = 0;

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

        size_t nextJacob = jacob + 2 * previusJacob;
        previusJacob = jacob;
        jacob = nextJacob;
    }

    return sequence;
}

void    PmergeMe::sortDeque()
{
    if (_deque.size() <= 1)
        return;

    std::deque<ChainElement> mainChain;
    std::deque<int> pending;
    std::deque<int> result;

    buildMainAndPending(mainChain, pending);
    insertPending(mainChain, pending);

    for (size_t i = 0; i < mainChain.size(); i++)
    {
        result.push_back(mainChain[i].value);
    }
    _deque = result;    
}

void    PmergeMe::buildMainAndPending(std::deque<ChainElement>& mainChain,
            std::deque<int>& pending)
{
    for (size_t i = 0; i < _pairsDeque.size(); i++)
    {
        ChainElement element;

        element.value = _pairsDeque[i].large;
        element.pairId = _pairsDeque[i].id;

        mainChain.push_back(element);

        pending.push_back(_pairsDeque[i].small);
    }

    if (_deque.size() % 2 != 0)
        pending.push_back(_deque.back());
}

void    PmergeMe::insertPending(std::deque<ChainElement>& mainChain,
            std::deque<int>& pending)
{
    size_t processed = 1;
    size_t jacob = 3;
    size_t previusJacob = 1;

    ChainElement firstElement;

    firstElement.value = _pairsDeque[0].small;
    firstElement.pairId = _pairsDeque[0].id;

    mainChain.insert(mainChain.begin(), firstElement);

    while (processed < pending.size())
    {
        size_t end = jacob;

        if (end > pending.size())
            end = pending.size();

        for (size_t position = end; position > processed; position--)
        {
            size_t index = position - 1;
            size_t limit = mainChain.size();

            if (index < _pairsDeque.size())
            {
                for (size_t i = 0; i < mainChain.size(); i++)
                {
                    if (mainChain[i].pairId == _pairsDeque[index].id)
                    {
                        limit = i;
                        break;
                    }
                }
            }

            size_t right = limit;
            size_t left = 0;

            while (left < right)
            {
                size_t middle = left + (right - left) / 2;

                if (mainChain[middle].value < pending[index])  
                    left = middle + 1;
                else
                    right = middle;              
            }
            ChainElement element;

            element.value = pending[index];
            element.pairId = index < _pairsDeque.size()
            ? _pairsDeque[index].id : _pairsDeque.size();

            mainChain.insert(mainChain.begin() + left, element);           
        }

        processed = end;

        size_t nextJacob = jacob + 2 * previusJacob;
        previusJacob = jacob;
        jacob = nextJacob;
    }
    
}

void    PmergeMe::executeDeque()
{
    sortDequePairs();
    buildDequePairs();
    sortDequePairsByMax(_pairsDeque);
    sortDeque();
}

void    PmergeMe::execute(char* argv[])
{
    std::clock_t start;

    if (!parsing(argv))
        throw std::runtime_error("invalid input");
        
    saveOriginalValues(argv);

    start = std::clock();
    if (!addNumbersVector(argv))
        throw std::runtime_error("failure to add numbers to the vector");
    executeVector();
    _vectorTime = static_cast<double>(std::clock() - start) 
        / CLOCKS_PER_SEC * 1000000.0;

    start = std::clock();
    if (!addNumbersDeque(argv))
        throw std::runtime_error("failure to add numbers to the deque");
    executeDeque();
    _dequeTime = static_cast<double>(std::clock() - start) 
        / CLOCKS_PER_SEC * 1000000.0;
}

void    PmergeMe::printAll()
{
    size_t size = _vector.size();
    
    std::cout << "before: " << _beforeSort << std::endl;

    std::cout << "after: ";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << _vector[i];
        if (i + 1 < size)
            std::cout << " ";
    }

    std::cout << std::endl;

    /* std::cout << "deque: ";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << _deque[i];
        if (i + 1 < size)
            std::cout << " ";
    }

    std::cout << std::endl; */

    std::cout << "Time to process a range of " << _vector.size()
          << " elements with std::vector : "
          << _vectorTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _deque.size()
          << " elements with std::deque : "
          << _dequeTime << " us" << std::endl;
}
