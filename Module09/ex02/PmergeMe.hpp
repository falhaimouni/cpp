#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <ctime>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <sys/time.h>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    int run(int argc, char **argv);

private:
    bool isValidNumber(const std::string& str) const;
    bool parseInput(int argc, char **argv,
                    std::vector<int>& vec,
                    std::deque<int>& deq) const;
    long long getTimeInMicroseconds() const;
    void printVector(const std::vector<int>& vect) const;
    void printDeque(const std::deque<int>& deq) const;

    // Container-specific sorting
    void sortVector(std::vector<int>& vec) const;
    void sortDeque(std::deque<int>& deq) const;

    void binaryInsertVector(std::vector<int>& vec, int value) const;
    void binaryInsertDeque(std::deque<int>& deq, int value) const;

    long long timedSortVector(std::vector<int>& vec) const;
    long long timedSortDeque(std::deque<int>& deq) const;
};

#endif
