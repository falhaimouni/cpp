#include "Serializer.hpp"

int main()
{
    Data data;

    data.a = 7;
    data.b = 's';

    std::cout << &data << std::endl;
    std::cout << data.a << std::endl;
    std::cout << data.b << std::endl;

    uintptr_t var = Serializer::serialize(&data);
    Data *data1 = Serializer::deserialize(var);

    std::cout << &data1 << std::endl;
    std::cout << data1->a << std::endl;
    std::cout << data1->b << std::endl;
}