#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 5; ++i)
    {
        Base* base = generate();
        identify(base);
        identify(*base);
        delete base;
        std::cout << "------------------\n";
    }

    return 0;
}
