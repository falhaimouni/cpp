#ifndef RBN_HPP
# define RBN_HPP

#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>

class RPN
{
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
};

int eval(std::vector<std::string>& A);


#endif