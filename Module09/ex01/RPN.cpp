#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& other)
{
    (void)other;
}

RPN& RPN::operator=(const RPN& other)
{
    (void)other;
    return (*this);
}

RPN::~RPN(){}

int eval(const std::string& expr)
{
    std::stack<int> st;
    std::istringstream iss(expr);
    std::string token;
    bool sawToken = false;

    while (iss >> token)
    {
        sawToken = true;
        if (token != "+" && token != "-" && token != "/"
            && token != "*") {
            for (size_t j = 0; j < token.size(); j++)
            {
                if (!std::isdigit(token[j]) && !(j == 0 && token[j] == '-'))
                {
                    std::cerr << "Error" << std::endl;
                    exit(1);
                }
            }
            int val = std::atoi(token.c_str());
            if (val < -9 || val > 9)
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
            st.push(val);
            continue;
        }
        else
        {
            if (st.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if (token == "+")
                st.push(a + b);
            else if (token == "-")
                st.push(a - b);
            else if (token == "*")
                st.push(a * b);
            else {
                if (b == 0)
                {
                    std::cerr << "Error" << std::endl;
                    exit(1);
                }
                st.push(a / b);
            }
        }
    }
    if (!sawToken) {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    if (st.size() != 1) {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    return st.top();
}
