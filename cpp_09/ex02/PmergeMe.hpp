#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <string>

struct ChainElement
{
    int value;
    size_t pairId;
};

struct Pairs
{
    int small;
    int large;
    size_t  id;
};

struct Losers
{
    Pairs   pair;
    size_t  winnerId;
};


class PmergeMe
{
private:
    double  _vectorTime;
    double  _dequeTime;
    std::string _beforeSort;

    std::vector<Pairs>  _pairsVector;
    std::vector<int> _vector;

    std::deque<Pairs>   _pairsDeque;
    std::deque<int> _deque;

    bool    parsing(char* argv[]) const;
    bool    addNumbers(char* argv[]);
    void    saveOriginalValues();

    void    sortVectorPairs();
    void    buildVectorPairs();
    void    buildWinners(std::vector<Pairs>& pairs, std::vector<Pairs>& winners,
                std::vector<Losers>& losers);
    void    sortVectorPairsByMax(std::vector<Pairs>& pairs);
    std::vector<Pairs> buildSequence(std::vector<Pairs>& winners,
                std::vector<Pairs>& pending);
    void    sortVector();
    void    buildMainAndPending(std::vector<ChainElement>& mainChain,
                std::vector<int>& pending);
    void    insertPending(std::vector<ChainElement>& mainChain,
                std::vector<int>& pending);
    void    executeVector();

    void    sortDequePairs();
    void    buildDequePairs();
    void    buildWinners(std::deque<Pairs>& pairs, std::deque<Pairs>& winners,
                std::deque<Losers>& losers);
    void    sortDequePairsByMax(std::deque<Pairs>& pairs);
    std::deque<Pairs> buildSequence(std::deque<Pairs>& winners,
                std::deque<Pairs>& pending);
    void    sortDeque();
    void    buildMainAndPending(std::deque<ChainElement>& mainChain,
                std::deque<int>& pending);
    void    insertPending(std::deque<ChainElement>& mainChain,
                std::deque<int>& pending);
    void    executeDeque();
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe&   operator=(const PmergeMe& other);
    ~PmergeMe();

    void    execute(char* argv[]);
    void    printAll();

};

#endif