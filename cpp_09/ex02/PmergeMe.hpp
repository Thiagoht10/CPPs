#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
private:
    std::string _beforeSort;

    std::vector<int> _vector;
    std::vector<int> _mainChain;
    std::vector<int> _pending;

    std::deque<int> _deque;

    bool    parsing(char* argv[]) const;
    bool    addNumbers(char* argv[]);
    void    saveOriginalValues();

    void    sortVectorPairs();
    void    buildPairs();
    void    sortVectorPairsByMax();
    void    buildMainAndPending();


public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe&   operator=(const PmergeMe& other);
    ~PmergeMe();

    void    execute(char* argv[]);
    void    printAll();

};

#endif