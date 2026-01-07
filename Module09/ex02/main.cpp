#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe sorter;
    int err = sorter.run(argc, argv);
    return err; 
}