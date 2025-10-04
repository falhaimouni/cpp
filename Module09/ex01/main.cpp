#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    char *expr = argv[1];
    const char *del = " ";
    char *tok = std::strtok(expr, del);
    std::vector<std::string> num;
    while (tok)
    {
        num.push_back(tok);
        tok = std::strtok(NULL, del);
    }
    if (num.empty())
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    int res = eval(num);
    std::cout << res << std::endl;
    return (0);
}
