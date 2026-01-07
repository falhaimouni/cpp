#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string& str) const
{
    for (size_t i = 0; i < str.size(); i++)
        if (!std::isdigit(str[i]))
            return false;
    return true;
}

bool PmergeMe::parseInput(int argc, char **argv,
                          std::vector<int>& vec,
                          std::deque<int>& deq) const
{
    for (int i = 1; i < argc; ++i)
    {
        if (!isValidNumber(argv[i]))
            return false;
        long num = std::atol(argv[i]);
        if (num <= 0 || num > INT_MAX)
            return false;
        vec.push_back(num);
        deq.push_back(num);
    }
    return true;
}

long long PmergeMe::getTimeInMicroseconds() const
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000LL + tv.tv_usec;
}

void PmergeMe::printVector(const std::vector<int>& vect) const
{
    for (size_t i = 0; i < vect.size(); ++i)
        std::cout << vect[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printDeque(const std::deque<int>& deq) const
{
    for (size_t i = 0; i < deq.size(); ++i)
        std::cout << deq[i] << " ";
    std::cout << std::endl;
}

// ---------------- Vector Sorting ----------------

void PmergeMe::binaryInsertVector(std::vector<int>& vec, int value) const
{
    std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(it, value);
}

void PmergeMe::sortVector(std::vector<int>& vec) const
{
    if (vec.size() <= 1)
        return;

    std::vector<std::pair<int,int> > pairs;
    bool hasStraggler = (vec.size() % 2 != 0);
    int straggler = 0;

    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        int a = vec[i];
        int b = vec[i+1];
        if (a < b)
            std::swap(a,b);
        pairs.push_back(std::make_pair(a,b));
    }

    if (hasStraggler)
        straggler = vec.back();

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    sortVector(mainChain);

    for (size_t i = 0; i < pairs.size(); ++i)
        binaryInsertVector(mainChain, pairs[i].second);

    if (hasStraggler)
        binaryInsertVector(mainChain, straggler);

    vec = mainChain;
}

long long PmergeMe::timedSortVector(std::vector<int>& vec) const
{
    long long start = getTimeInMicroseconds();
    sortVector(vec);
    long long end = getTimeInMicroseconds();
    return end - start;
}

// ---------------- Deque Sorting ----------------

void PmergeMe::binaryInsertDeque(std::deque<int>& deq, int value) const
{
    std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), value);
    deq.insert(it, value);
}

void PmergeMe::sortDeque(std::deque<int>& deq) const
{
    if (deq.size() <= 1)
        return;

    std::vector<std::pair<int,int> > pairs;
    bool hasStraggler = (deq.size() % 2 != 0);
    int straggler = 0;

    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        int a = deq[i], b = deq[i+1];
        if (a < b) std::swap(a,b);
        pairs.push_back(std::make_pair(a,b));
    }

    if (hasStraggler)
        straggler = deq.back();

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    sortDeque(mainChain);

    for (size_t i = 0; i < pairs.size(); ++i)
        binaryInsertDeque(mainChain, pairs[i].second);

    if (hasStraggler)
        binaryInsertDeque(mainChain, straggler);

    deq = mainChain;
}

long long PmergeMe::timedSortDeque(std::deque<int>& deq) const
{
    long long start = getTimeInMicroseconds();
    sortDeque(deq);
    long long end = getTimeInMicroseconds();
    return end - start;
}

// ---------------- Run ----------------

int PmergeMe::run(int argc, char **argv)
{
    std::vector<int> vec;
    std::deque<int> deq;

    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    if (!parseInput(argc, argv, vec, deq))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    printVector(vec);

    long long timeVec = timedSortVector(vec);
    long long timeDeq = timedSortDeque(deq);

    std::cout << "After: ";
    printVector(vec);

    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << timeVec << " us\n";
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque : " << timeDeq << " us\n";

    return 0;
}
