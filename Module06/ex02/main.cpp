#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base* r = generate();
    identify(r);
    identify(*r);
    delete r;
}
