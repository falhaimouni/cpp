#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    std::string expr = argv[1];
    int res = eval(expr);
    std::cout << res << std::endl;
    return (0);
}
