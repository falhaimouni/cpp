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

int eval(std::vector<std::string>& A)
{
    std::stack<int> st;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] != "+" && A[i] != "-" && A[i] != "/"
            && A[i] != "*") {
            for (size_t j = 0; j < A[i].size(); j++)
            {
                if (!std::isdigit(A[i][j]) && !(j == 0 && A[i][j] == '-'))
                {
                    std::cerr << "Error" << std::endl;
                    exit(1);
                }
            }
            int val = std::atoi(A[i].c_str());
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

            if (A[i] == "+")
                st.push(a + b);
            else if (A[i] == "-")
                st.push(a - b);
            else if (A[i] == "*")
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
    if (st.size() != 1) {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    return st.top();
}
