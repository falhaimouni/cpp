#ifndef RBN_HPP
# define RBN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
#include <iterator>
#include <sstream>
#include <cctype>

class RPN
{
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
};

int eval(const std::string& expr);


#endif